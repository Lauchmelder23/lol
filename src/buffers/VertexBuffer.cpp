#include <lol/buffers/VertexBuffer.hpp>

namespace lol
{
	BufferLayout::BufferLayout(const std::initializer_list<VertexAttribute>& attributes) :
		layout(attributes), stride(0)
	{
		// Calculate stride and offsets of elements
		for (VertexAttribute& attribute : layout)
		{
			attribute.offset += stride;
			stride += (attribute.size * SizeOf(attribute.type));
		}
	}


	VertexBuffer::VertexBuffer(const std::vector<float>& data, Usage usage) :
		Buffer(BufferType::Array), layout{}
	{
		glBufferData(NATIVE(type), data.size() * sizeof(float), data.data(), NATIVE(usage));
	}
}