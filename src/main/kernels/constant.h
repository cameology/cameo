#ifndef CONSTANT_H
#define CONSTANT_H

#include <unordered_map>
#include <string>
#include <variant>



namespace Token {
    enum Type {
        Keyword,
        Special,
        Operator,
        Identifier,
    };

    enum KeywordType {
        Variable,
        Class,
        Function,
        Condition,
        Loop,
        Expression,
    };
};

#endif