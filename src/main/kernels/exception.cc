#include "exception.h"

#include <exception>
#include <string>



namespace Exception {
    Exception::Exception() {}
    Exception::~Exception() {}
    Exception::Exception(std::string message) {
        this->message = message;
    };

    UnexpectedToken::UnexpectedToken() {
        this->message = "unexpected token";
    };

    InvalidDatatype::InvalidDatatype() {
        this->message = "Invalid Datatype";
    };
};