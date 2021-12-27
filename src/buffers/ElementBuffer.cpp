#include <lol/buffers/ElementBuffer.hpp>

namespace lol
{
	ElementBuffer::ElementBuffer(const std::vector<unsigned int>& elements, Usage usage) :
		Buffer(BufferType::ElementArray), count(count)
	{
		glBufferData(NATIVE(type), elements.size() * sizeof(unsigned int), elements.data(), NATIVE(usage));
	}
}