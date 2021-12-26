#include <lol/Buffer.hpp>

namespace lol
{
	Buffer::Buffer(BufferType type) :
		id(0), type(type)
	{
		glGenBuffers(1, &id);
		glBindBuffer(NATIVE(type), id);
	}

	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &id);
	}

	void* Buffer::Map(Access access)
	{
		return glMapBuffer(NATIVE(type), NATIVE(access));
	}

	void Buffer::Unmap()
	{
		glUnmapBuffer(NATIVE(type));
	}

	void Buffer::Bind()
	{
		glBindBuffer(NATIVE(type), id);
	}

	void Buffer::Unbind()
	{
		glBindBuffer(NATIVE(type), 0);
	}
}