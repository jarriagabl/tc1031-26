#ifndef KEY_NOT_FOUND_EXCEPTION_H
#define KEY_NOT_FOUND_EXCEPTION_H

#include <exception>

class KeyNotFoundException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Key not found in table";
    }
};

#endif