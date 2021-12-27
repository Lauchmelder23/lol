#include <lol/buffers/ElementBuffer.hpp>

namespace lol
{
	ElementBuffer::ElementBuffer(const std::vector<unsigned int>& elements, Usage usage) :
<<<<<<< HEAD
		Buffer(BufferType::ElementArray), count(elements.size())
=======
		Buffer(BufferType::ElementArray), count(count)
>>>>>>> 7b071b2db64f25ad5bfd602c42dd8f17b75e3948
	{
		glBufferData(NATIVE(type), elements.size() * sizeof(unsigned int), elements.data(), NATIVE(usage));
	}
}