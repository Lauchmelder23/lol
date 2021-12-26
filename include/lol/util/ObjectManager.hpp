#pragma once

#include <map>
#include <memory>

namespace lol
{

	/**
	 * Some objects should only exist once but be available to multiple objects (e.g. multiple
	 * models sharing the same VAO and shaders. Any object can register objects here and other
	 * objects can then retrieve them if they have the ID.
	 *
	 * Objects are stored and returned as shared_ptr's, so even if a part of the program deletes
	 * an object from the manager, any part of the program that has the objects stored in them will
	 * not break and still work. But realistically this shouldn't happen in the first place.
	 * As a consequence, even if no objects are using an object stored in here it will continue to
	 * exist.
	 */
	template<typename Type>
	class ObjectManager : public NonCopyable
	{
	public:
		static ObjectManager<Type>& GetInstance()
		{
			static ObjectManager<Type> instance;
			return instance;
		}

		/**
		 * Add new (existing) object to manager
		 */
		inline void Register(unsigned int id, const std::shared_ptr<Type>& obj)
		{
			objects.insert(std::make_pair(id, obj));
		}

		/**
		 * Remove object from manager
		 */
		inline void Delete(unsigned int id)
		{
			objects.erase(id);
		}

		/**
		 * Retrieve object from manager
		 */
		inline std::shared_ptr<Type> Get(unsigned int id)
		{
			auto it = objects.find(id);

			if (it == objects.end())
				return nullptr;

			return it->second;
		}

		inline void Cleanup()
		{
			for(auto& [key, val] : objects)
			{
				if (val.use_count() < 3)	// I hope I don't forget about this if I ever go multithreaded
					objects.erase(key);
			}
		}

		inline void Return(unsigned int id)
		{
			auto it = objects.find(id);

			if (it == objects.end())
				return;

			if (it->second.use_count() < 3)	// I hope I don't forget about this if I ever go multithreaded
				objects.erase(it);
		}

	private:
		ObjectManager() {}

	private:
		std::map<unsigned int, std::shared_ptr<Type>> objects;
	};

}