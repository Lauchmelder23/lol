#include <lol/buffers/ElementBuffer.hpp>

namespace lol
{
	ElementBuffer::ElementBuffer(size_t count, const std::vector<unsigned int>& elements, Usage usage) :
		Buffer(BufferType::ElementArray), count(count)
	{
		glBufferData(NATIVE(type), count * sizeof(unsigned int), elements.data(), NATIVE(usage));
	}
}