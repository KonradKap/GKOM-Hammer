#pragma once

#include <exception>

class OpenGlException : public std::runtime_error {
    public:
        explicit OpenGlException(const std::string& what_arg) :
            std::runtime_error(what_arg) {};
        explicit OpenGlException(const char* what_arg) :
            std::runtime_error(what_arg) {};

        virtual ~OpenGlException() {};
};
