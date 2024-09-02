#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <regex>
#include <unordered_map> 

#include <kernels/constant.h>
#include <frontend/ast.h>



class Lexer {
    private:
        const std::unordered_map<std::string, std::vector<std::variant<Token::Type, std::string>>> KeywordMap = {
            { "if",             { Token::Type::Keyword, "if" } },
            { "else",           { Token::Type::Keyword, "else" } },
            { "switch",         { Token::Type::Keyword, "switch" } },
            { "case",           { Token::Type::Keyword, "case" } },
            { "default",        { Token::Type::Keyword, "default" } },
            { "break",          { Token::Type::Keyword, "break" } },

            // loops
            { "while",          { Token::Type::Keyword, "while" } },
            { "for",            { Token::Type::Keyword, "for" } },
            { "continue",       { Token::Type::Keyword, "continue" } },

            // Class
            { "interface",      { Token::Type::Keyword, "interface" } },
            { "class",          { Token::Type::Keyword, "class" } },
            { "extend",         { Token::Type::Keyword, "extend" } },
            { "implement",      { Token::Type::Keyword, "implement" } },
            { "private",        { Token::Type::Keyword, "private" } },
            { "protected",      { Token::Type::Keyword, "protected" } },
            { "public",         { Token::Type::Keyword, "public" } },
            
            // Datatypes
            { "string",         { Token::Type::Keyword, "string" } },
            { "int",            { Token::Type::Keyword, "int" } },
            { "float",          { Token::Type::Keyword, "float" } },
            { "double",         { Token::Type::Keyword, "double" } },
            { "boolean",        { Token::Type::Keyword, "boolean" } },
            { "void",           { Token::Type::Keyword, "void" } },

            // Special
            { "return",         { Token::Type::Keyword, "return" } },
        }; 

        const std::unordered_map<std::string, std::vector<std::variant<Token::Type, std::string>>> OperatorMap = {
            // Unary
            { "increment",      { Token::Type::Operator, "increment" } },              // ++
            { "decrement",      { Token::Type::Operator, "decrement" } },              // --
            { "unaryPlus",      { Token::Type::Operator, "unaryPlus" } },              // +X
            { "unaryMinus",     { Token::Type::Operator, "unaryMinus" } },             // -X

            // Arithmetic
            { "add",            { Token::Type::Operator, "add" } },                    // X + X
            { "substract",      { Token::Type::Operator, "substract" } },              // X - X
            { "multiply",       { Token::Type::Operator, "multiply" } },               // X * X
            { "divide",         { Token::Type::Operator, "divide" } },                 // X / X
            { "mod",            { Token::Type::Operator, "mod" } },                    // X % X

            // Logical
            { "and",            { Token::Type::Operator, "and" } },                    // X && X
            { "or",             { Token::Type::Operator, "or" } },                     // X || X
            { "not",            { Token::Type::Operator, "not" } },                    // !X
            { "ternary",        { Token::Type::Operator, "ternary" } },                // ? ... :

            // Relational
            { "equal",          { Token::Type::Operator, "equal" } },                  // ==
            { "gt",             { Token::Type::Operator, "gt" } },                     // >
            { "gte",            { Token::Type::Operator, "gte" } },                    // >=
            { "lt",             { Token::Type::Operator, "lt" } },                     // <
            { "lte",            { Token::Type::Operator, "lte" } },                    // <=
            { "notequal",       { Token::Type::Operator, "notequal" } },               // !=

            // Special
            { "assignment",     { Token::Type::Operator, "assignment" } },             // =
        };

        const std::unordered_map<std::string, std::vector<std::variant<Token::Type, std::string>>> IdentifierMap = {
            { "variable",       { Token::Type::Identifier, "variable" } },
            { "value",          { Token::Type::Identifier, "value" } },
            { "returnvalue",    { Token::Type::Identifier, "returnvalue" } },
            { "functionName",   { Token::Type::Identifier, "functionName" } },
            { "param",          { Token::Type::Identifier, "param" } },
            { "classname",      { Token::Type::Identifier, "classname" } },
        };

        const std::unordered_map<std::string, std::vector<std::variant<Token::Type, std::string>>> SpecialMap = {
            { "brackets",       { Token::Type::Special, "brackets" } },               // []
            { "parentheses",    { Token::Type::Special, "parentheses" } },            // ()
            { "braces",         { Token::Type::Special, "braces" } },                 // {}
            { "comma",          { Token::Type::Special, "comma" } },                  // ,
            { "semicolon",      { Token::Type::Special, "semicolon" } },              // ;
            { "period",         { Token::Type::Special, "period" } },                 // .
        };

        AbstractSyntaxTree::VariableNode variableProcessor(std::string line);

    public:
        Lexer();

        AbstractSyntaxTree::VariableNode serialize(std::string line);

        ~Lexer();
};

#endif