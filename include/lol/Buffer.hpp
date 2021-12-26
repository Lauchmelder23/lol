#pragma once

#include <memory>
#include <vector>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	/**
	 * @brief Represents a generic buffer object. The buffer is destroyed together with the object
	 * 
	 * For instantiation the derived types should be used (e.g. VertexBuffer)
	 */
	class Buffer : public NonCopyable
	{
	public:
		/**
		 * @brief Maps the data of the Buffer to memory
		 * 
		 * @param access The accessing mode for the memory buffer
		 * @return A pointer to the data in memory 
		 */
		void* Map(Access access);

		/**
		 * @brief Unmap the Buffer
		 */
		void Unmap();

		/**
		 * @brief Binds the Buffer
		 * 
		 */
		void Bind();

		/**
		 * @brief Unbinds the Buffer
		 */
		void Unbind();

	protected:
		/**
		 * @brief Construct a new Buffer object of the desired type
		 * 
		 * @param target Type of the buffer
		 */
		Buffer(BufferType target);
		virtual ~Buffer();

	protected:
		unsigned int id;
		BufferType type;
	};

}