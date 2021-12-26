#pragma once

#include <map>
#include <memory>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/Exceptions.hpp>

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
	class ObjectManager : public NonCopyable
	{
	public:
		ObjectManager() {}

		template<typename T, typename... Args>
		std::shared_ptr<T> Create(unsigned int id, Args... args)
		{
			std::shared_ptr<T> object = std::make_shared<T>(args...);
			objects.insert({id, object});

			return object;
		}

		/**
		 * Remove object from manager
		 */
		void Delete(unsigned int id);

		/**
		 * Retrieve object from manager
		 */
		std::shared_ptr<void> Get(unsigned int id);

		template<typename T>
		std::shared_ptr<T> Get(unsigned int id)
		{

			std::shared_ptr<void> object = Get(id);
			return std::static_pointer_cast<T>(object);
		}

		void ClearUnused();
		void Clear();

	private:
		std::map<unsigned int, std::shared_ptr<void>> objects;
	};

}