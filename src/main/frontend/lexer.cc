#include "lexer.h"

#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include <kernels/constant.h>
#include <kernels/exception.h>
#include <frontend/ast.h>

#include <stdexcept>



Lexer::Lexer() {
    
}

AbstractSyntaxTree::VariableNode Lexer::variableProcessor(std::string line) {
    std::smatch matches;
    std::vector<std::regex> query = {
        std::regex(
            "(string|int|float|double|boolean)"
            "\\s([a-zA-Z0-9]*)\\s=\\s([+-]?([0-9]*[.])?[0-9]+|\"(.*?)\"|true|false);"),
    };

    // Variable Checker
    if (std::regex_search(line, matches, query.at(0))) {
        auto datatype   = matches[1].str();
        auto value      = matches[3].str();

        // Integer Checker
        if ((datatype == "int") and !(std::regex_match(value, std::regex("^-?\\d+$")))) {
            throw Exception::InvalidDatatype();
        }

        // Float Checker
        if ((datatype == "float") and !(std::regex_match(value, std::regex("^[+-]?\\d*\\.\\d+$")))) {
            throw Exception::InvalidDatatype();
        }

        // String Checker
        if ((datatype == "string") and !(std::regex_match(value, std::regex("\"([^\"]*)\"")))) {
            throw Exception::InvalidDatatype();
        }

        // Boolean Checker
        if ((datatype == "boolean") and !(std::regex_match(value, std::regex("true|false")))) {
            throw Exception::InvalidDatatype();
        }

        return AbstractSyntaxTree::VariableNode(0, 0,
            AbstractSyntaxTree::Identifier(matches[2].str()),
            AbstractSyntaxTree::Value(datatype, value)
        );
    }

    throw Exception::UnexpectedToken();
}

AbstractSyntaxTree::VariableNode Lexer::serialize(std::string line) {
    int column = 0;

    std::vector<std::regex> query = {
        std::regex("(string|int|float|double|boolean)\\s(.*);"),                // Variable Declaration
        std::regex("(string|int|float|double|boolean|void)\\s[^{]*\\{"),        // Function Declaration
    };

    return this->variableProcessor(line);
}

Lexer::~Lexer() {}