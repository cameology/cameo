#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <exception>
#include <string>



namespace Exception {
    class Exception : public std::exception {
        protected:
            std::string message;

        public:
            Exception();
            Exception(std::string message);
            
            ~Exception();
    };

    class UnexpectedToken : public Exception {
        public:
            UnexpectedToken();
    };

    class InvalidDatatype : public Exception {
        public:
            InvalidDatatype();
    };
};

#endif