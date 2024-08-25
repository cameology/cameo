#ifndef CONSTANT_H
#define CONSTANT_H

#include <unordered_map>
#include <string>


namespace Token {
    enum Keyword {
        // branch
        If,
        Else,
        Switch,
        Case,
        Default,
        Break,

        // loops
        While,
        For,
        Continue,

        // Class
        Interface,
        Class,
        Extend,
        Implement,
        Private,
        Protected,
        Public,
        
        // Datatypes
        String,
        Int,
        Float,
        Double,
        Boolean,
        Void,

        // Special
        Return,
    };

    enum Special {
        Variable,
        Value,
        ReturnValue,
        FunctionName,
        Param,
        ClassName,
        Brackets,               // []
        Parentheses,            // ()
        Braces,                 // {}
        Comma,                  // ,
        Semicolon,              // ;
        Period,                 // .
    };

    enum Operator {
        // Unary
        Increment,              // ++
        Decrement,              // --
        UnaryPlus,              // +X
        UnaryMinus,             // -X

        // Arithmetic
        Add,                    // X + X
        Substract,              // X - X
        Multiply,               // X * X
        Divide,                 // X / X
        Mod,                    // X % X

        // Logical
        And,                    // X && X
        Or,                     // X || X
        Not,                    // !X
        Ternary,                // ? ... :

        // Relational
        Equal,                  // ==
        Gt,                     // >
        Gte,                    // >=
        Lt,                     // <
        Lte,                    // <=
        NotEqual,               // !=

        // Special
        Assignment,             // =
    };

    template <typename T> std::string str(T token) {
        switch(token) {
            case Keyword::If:
                return "if";
            case Keyword::Else:
                return "else";
            case Keyword::Switch:
                return "switch";
            case Keyword::Case:
                return "case";
            case Keyword::Default:
                return "default";
            case Keyword::Break:
                return "break";
            case Keyword::While:
                return "while";
            case Keyword::For:
                return "for";
            case Keyword::Continue:
                return "continue";
            case Keyword::Interface:
                return "interface";
            case Keyword::Class:
                return "class";
            case Keyword::Extend:
                return "extend";
            case Keyword::Implement:
                return "implement";
            case Keyword::Private:
                return "private";
            case Keyword::Protected:
                return "protected";
            case Keyword::Public:
                return "public";
            case Keyword::String:
                return "string";
            case Keyword::Int:
                return "int";
            case Keyword::Float:
                return "float";
            case Keyword::Double:
                return "double";
            case Keyword::Boolean:
                return "boolean";
            case Keyword::Void:
                return "void";
            case Keyword::Return:
                return "return";
            case Special::Brackets:
                return "brackets";
            case Special::Parentheses:
                return "parentheses";
            case Special::Braces:
                return "braces";
            case Special::Comma:
                return "comma";
            case Special::Semicolon:
                return "semicolon";
            case Special::Period:
                return "period";
            case Operator::Increment:
                return "increment";
            case Operator::Decrement:
                return "decrement";
            case Operator::UnaryPlus:
                return "unrplus";
            case Operator::UnaryMinus:
                return "unrminus";
            case Operator::Add:
                return "add";
            case Operator::Substract:
                return "substract";
            case Operator::Multiply:
                return "multiply";
            case Operator::Divide:
                return "divide";
            case Operator::Mod:
                return "mod";
            case Operator::And:
                return "and";
            case Operator::Or:
                return "or";
            case Operator::Not:
                return "not";
            case Operator::Ternary:
                return "ternary";
            case Operator::Equal:
                return "equal";
            case Operator::Gt:
                return "gt";
            case Operator::Gte:
                return "gte";
            case Operator::Lt:
                return "lt";
            case Operator::Lte:
                return "lte";
            case Operator::NotEqual:
                return "nequal";
            case Operator::Assignment:
                return "assign";
            default:
                return "";
        }
    };
};

#endif