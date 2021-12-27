#pragma once

#include <lol/Buffer.hpp>

namespace lol
{
	/**
	 * @brief Stores attribute data for one vertex
	 * 
	 */
	struct VertexAttribute
	{
		int size;			///< Number of elements in this attribute
		Type type;			///< Type of the attribute
		bool normalized;	///< Whether the data is normalized
		int offset;			///< Offset of the attribute into the vertex data

		/**
		 * @brief Construct a new VertexAttribute
		 * 
		 * @param type 			Datatype of the attribute
		 * @param count 		Number of elements in this attribute
		 * @param normalized 	If data is normalized
		 */
		VertexAttribute(Type type, unsigned int count, bool normalized) :
			type(type), size(count), normalized(normalized), offset(0)
		{ }
	};

	/**
	 * @brief Stored the layout of a VertexBuffer
	 */
	class BufferLayout
	{
	public:
		/**
		 * @brief Construct a new BufferLayout
		 * 
		 * @param attributes A list of vertex attributes making up the layout
		 */
		BufferLayout(const std::initializer_list<VertexAttribute>& attributes);

		/**
		 * @brief Returns the stored layout
		 * 
		 * @return A list of VertexAttributes 
		 */
		inline const std::vector<VertexAttribute>& GetLayout() const { return layout; }

		/**
		 * @brief Get the stride of the layout
		 * 
		 * The stride is the size of one vertex in the buffer in bytes.
		 * The more attributes a vertex has, the larger its stride will be
		 * 
		 * @return Number of bytes per vertex
		 */
		inline int GetStride() const { return stride; }

		/**
		 * @brief Returns iterator to beginning of layout list
		 * 
		 * @return Iterator to beginning of list 
		 */
		std::vector<VertexAttribute>::const_iterator begin() const { return layout.begin(); }

		/**
		 * @brief Returns iterator to end of layout list
		 * 
		 * @return Iterator to end of list 
		 */
		std::vector<VertexAttribute>::const_iterator end() const { return layout.end(); }

	private:
		std::vector<VertexAttribute> layout;
		int stride;
	};

	/**
	 * @brief Represents a VBO and manages its state
	 */
	class VertexBuffer : public Buffer
	{
	public:
		/**
		 * @brief Construct a new VertexBuffer
		 * 
		 * @param data 	Data to put into the buffer
		 * @param usage Hint OpenGL on how the buffer will be used
		 */
		VertexBuffer(const std::vector<float>& data, Usage usage = Usage::StaticDraw);

		/**
		 * @brief Set the BufferLayout of this VBO
		 * 
		 * @param layout The new layout to give to this buffer
		 */
		inline void SetLayout(const BufferLayout& layout) { this->layout = layout; };

		/**
		 * @brief Get the VBOs BufferLayout
		 *
		 * @return The stored BufferLayout 
		 */
		inline const BufferLayout& GetLayout() { return layout; }

	private:
		BufferLayout layout;
	};
}