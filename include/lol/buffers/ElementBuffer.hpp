#pragma once

#include <lol/Buffer.hpp>

namespace lol
{
	/**
	 * @brief Represents an EBO and manages its state
	 */
	class ElementBuffer : public Buffer
	{
	public:
		/**
		 * @brief Construct a new ElementBuffer
		 * 
		 * @param elements 	Data to put into the buffer
		 * @param usage 	Hint OpenGL on how the buffer will be used
		 */
		ElementBuffer(const std::vector<unsigned int>& elements, Usage usage = Usage::StaticDraw);

		/**
		 * @brief Get the number of indices in the buffer
		 * 
		 * @return Number of indices inside the buffer
		 */
		inline size_t GetCount() const { return count; }

	private:
		size_t count;
	};
}