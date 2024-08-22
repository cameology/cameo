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
                return "If";
            case Keyword::Else:
                return "Else";
            case Keyword::Switch:
                return "Switch";
            case Keyword::Case:
                return "Case";
            case Keyword::Default:
                return "Default";
            case Keyword::Break:
                return "Break";
            default:
                return "";
        }
    };
};

#endif