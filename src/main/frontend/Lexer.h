#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

#include <kernels/type.h>



class Lexer {
    public:
        Lexer();

        std::vector<Type::LexerDetail> serialize(std::string line);

        ~Lexer();
};

#endif