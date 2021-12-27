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
        for(std::map<unsigned int, std::shared_ptr<void>>::iterator it = objects.begin(); it != objects.end();)
        {
            if (it->second.unique())
                it = objects.erase(it);
            else
                it++;
        }
    }

	void ObjectManager::Clear()
    {
        objects.clear();
    }
}