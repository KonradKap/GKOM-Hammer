#pragma once

#include <exception>

class ShaderException : public std::runtime_error {
    public:
        explicit ShaderException(const std::string& what_arg) :
            std::runtime_error(what_arg) {};
        explicit ShaderException(const char* what_arg) :
            std::runtime_error(what_arg) {};

        virtual ~ShaderException() {};
};
