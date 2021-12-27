#pragma once

#include <stdexcept>
#include <string>

#define TYPENAME(x) #x

namespace lol
{
    /**
     * @brief The requested object was not found
     * 
     * Thrown by ObjectManager::Get() if the specified ID isn't associated
     * with any objects in the manager
     */
    class ObjectNotFoundException : public std::runtime_error
    {
    public:
        /**
         * @brief Construct a new ObjectNotFoundException
         * 
         * @param id ID of the object that was not found
         */
        ObjectNotFoundException(unsigned int id) :
            std::runtime_error("Failed to Get() object with ID " + std::to_string(id) + " from ObjectManager. It does not exist.")
        { }
    };
}