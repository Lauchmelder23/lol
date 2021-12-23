#pragma once

#include <lol/util/NonCopyable.hpp>

#define PRODUCT(type) friend class Factory<type>

namespace lol
{

	template<typename Type>
	class Factory : public NonCopyable
	{
	public:
		~Factory() {}

		template<typename... Args>
		inline static std::shared_ptr<Type> Produce(Args&&... args)
		{
			return std::shared_ptr<Type>(new Type(args...));
		}

	private:
		Factory() {}
	};

}