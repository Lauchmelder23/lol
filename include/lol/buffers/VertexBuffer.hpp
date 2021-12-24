#pragma once

#include <lol/Buffer.hpp>

namespace lol
{
	struct VertexAttribute
	{
		int size;
		Type type;
		bool normalized;
		int offset;

		VertexAttribute(Type type, unsigned int count, bool normalized) :
			type(type), size(count), normalized(normalized), offset(0)
		{ }
	};

	class BufferLayout
	{
	public:
		BufferLayout(const std::initializer_list<VertexAttribute>& attributes);

		inline const std::vector<VertexAttribute>& GetLayout() const { return layout; }
		inline int GetStride() const { return stride; }

		std::vector<VertexAttribute>::const_iterator begin() const { return layout.begin(); }
		std::vector<VertexAttribute>::const_iterator end() const { return layout.end(); }

	private:
		std::vector<VertexAttribute> layout;
		int stride;
	};

	class VertexBuffer : public Buffer
	{
	public:
		VertexBuffer(size_t size, const std::vector<float>& data, Usage usage = Usage::StaticDraw);

		inline void SetLayout(const BufferLayout& layout) { this->layout = layout; };
		inline const BufferLayout& GetLayout() { return layout; }

	private:
		BufferLayout layout;
	};
}