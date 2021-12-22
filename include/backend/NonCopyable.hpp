#pragma once

namespace lol
{
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

