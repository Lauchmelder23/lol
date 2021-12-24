#include <lol/buffers/VertexBuffer.hpp>
#pragma once

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


	VertexBuffer::VertexBuffer(size_t size, float* data, Usage usage) :
		Buffer(BufferType::Array), layout{}
	{
		glBufferData(NATIVE(type), size * sizeof(float), (void*)data, NATIVE(usage));
	}
}