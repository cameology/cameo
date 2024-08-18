#ifndef CONSTANT_H
#define CONSTANT_H

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
};

#endif