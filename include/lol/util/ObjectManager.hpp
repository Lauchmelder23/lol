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
		inline void Register(unsigned int id, Type obj)
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
		inline Type Get(unsigned int id)
		{
			auto it = objects.find(id);

			if (it == objects.end())
				return nullptr;

			return it->second;
		}

	private:
		ObjectManager() {}

	private:
		std::map<unsigned int, Type> objects;
	};

}