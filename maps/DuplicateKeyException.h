#ifndef DUPLICATE_KEY_EXCEPTION_H
#define DUPLICATE_KEY_EXCEPTION_H

#include <exception>

class DuplicateKeyException : public std::exception
{
    virtual const char* what() const noexcept
    {
        return "Key already in table";
    }
};

#endif