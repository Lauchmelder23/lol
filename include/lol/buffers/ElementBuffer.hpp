#pragma once

#include <lol/Buffer.hpp>

namespace lol
{
	class ElementBuffer : public Buffer
	{
	public:
		ElementBuffer(size_t count, const std::vector<unsigned int>& elements, Usage usage = Usage::StaticDraw);

		inline size_t GetCount() const { return count; }

	private:
		size_t count;
	};
}