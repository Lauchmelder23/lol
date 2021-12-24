#include <lol/VertexArrayObject.hpp>

#include <assert.h>
#include <glad/glad.h>

namespace lol
{

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &id);
	}

	VertexArray::VertexArray(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<ElementBuffer>& elementBuffer) :
		id(0)
	{
		glGenVertexArrays(1, &id);

		SetVertexBuffer(vertexBuffer);
		SetElementBuffer(elementBuffer);

		glBindVertexArray(0);
	}
	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	void VertexArray::SetVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer)
	{
		glBindVertexArray(id);
		buffer->Bind();

		// Set up pipeline layout
		unsigned int index = 0;
		const BufferLayout& layout = buffer->GetLayout();
		for (const VertexAttribute& attribute : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, attribute.size, NATIVE(attribute.type), attribute.normalized, layout.GetStride(), (void*)(attribute.offset));

			index++;
		}

		vertexBuffer = buffer;
	}

	void VertexArray::SetElementBuffer(const std::shared_ptr<ElementBuffer>& buffer)
	{
		glBindVertexArray(id);
		buffer->Bind();

		elementBuffer = buffer;
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(id);
	}

	void Unbind()
	{
		glBindVertexArray(0);
	}
}