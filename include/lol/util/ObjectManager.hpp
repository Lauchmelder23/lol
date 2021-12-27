#pragma once

#include <map>
#include <memory>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/Exceptions.hpp>

namespace lol
{

	/**
	 * @brief Manages objects and cleans them up if they're not needed anymore.
	 * 
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
		/**
		 * @brief Construct a new ObjectManager
		 * 
		 */
		ObjectManager() {}

		/**
		 * @brief Tell the ObjectManager to create a new object of type T
		 * 
		 * The object will be constructed by the manager, ObjectManager will
		 * own it.
		 * 
		 * @tparam T 		Type of the object to create
		 * @tparam Args 	
		 * @param id 		ID to give this object in the manager
		 * @param args 		Argumnts to pass to T's constructor
		 * @return 			A shared pointer to the newly constructed object
		 */
		template<typename T, typename... Args>
		std::shared_ptr<T> Create(unsigned int id, Args... args)
		{
			std::shared_ptr<T> object = std::make_shared<T>(args...);
			objects.insert({id, object});

			return object;
		}

		/**
		 * @brief Remove object from manager
		 * 
		 * @param id ID of the object to remove
		 */
		void Delete(unsigned int id);

		/**
		 * @brief Retrieve a generic object from manager
		 * 
		 * The object returned will essentially be a void*. 
		 * The ObjectManager performs no casting.
		 * 
		 * @param id ID of the object to retrieve
		 * @return A void* to a blob of data making up the object
		 */
		std::shared_ptr<void> Get(unsigned int id);

		/**
		 * @brief Retriege an object of a specific type from the manager
		 * 
		 * @tparam T 	Type of the object
		 * @param id 	ID of the object
		 * @return 		A pointer to the object
		 */
		template<typename T>
		std::shared_ptr<T> Get(unsigned int id)
		{

			std::shared_ptr<void> object = Get(id);
			return std::static_pointer_cast<T>(object);
		}

		/**
		 * @brief Removes any objects that aren't in use by anyone anymore
		 * 
		 * Deletes any stored shared_ptr if their use count is equal to 1.
		 * Note that if you're holding a weak pointer to one of the objects it
		 * might be deleted at any time
		 */
		void ClearUnused();

		/**
		 * @brief Removes all objects from the manager
		 * 
		 * If an object holds a shared_ptr from the manager then this
		 * will not break the object. This merely causes the manager
		 * to "untrack" all objects.
		 */
		void Clear();

	private:
		std::map<unsigned int, std::shared_ptr<void>> objects;
	};

}