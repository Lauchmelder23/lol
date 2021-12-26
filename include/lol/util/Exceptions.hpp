#pragma once

#include <stdexcept>
#include <string>

#define TYPENAME(x) #x

namespace lol
{
    class ObjectNotFoundException : public std::runtime_error
    {
    public:
        ObjectNotFoundException(unsigned int id) :
            std::runtime_error("Failed to Get() object with ID " + std::to_string(id) + " from ObjectManager. It does not exist.")
        { }
    };
}