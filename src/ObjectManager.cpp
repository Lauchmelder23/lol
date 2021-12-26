#include <lol/util/ObjectManager.hpp>

namespace lol
{
    std::shared_ptr<void> ObjectManager::Get(unsigned int id)
    {
        auto it = objects.find(id);

        if(it == objects.end())
            throw ObjectNotFoundException(id);

        return it->second;
    }

    void ObjectManager::Delete(unsigned int id)
    {
        objects.erase(id);
    }

    void ObjectManager::ClearUnused()
    {
        for(const auto& [key, value] : objects)
        {
            if(value.unique())
                objects.erase(key);
        }
    }

	void ObjectManager::Clear()
    {
        objects.clear();
    }
}