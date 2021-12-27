#pragma once

namespace lol
{
	/**
	 * @brief An object without copy constructors or assignment operators.
	 * 
	 * Any object inheriting from this will not be able to be copied anymore
	 */
	class NonCopyable
	{
	public:
		NonCopyable(const NonCopyable& other) = delete;
		void operator=(const NonCopyable& other) = delete;

	protected:
		NonCopyable() {}
		~NonCopyable() {}
	};
}

