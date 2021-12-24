#pragma once

#include <memory>
#include <vector>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	/**
	 * @brief Represents a generic buffer object. The buffer is destroyed together with the object
	 */
	class Buffer : public NonCopyable
	{
	public:
		void* Map(Access access);
		void Unmap();

		void Bind();
		void Unbind();

	protected:
		Buffer(BufferType target);
		virtual ~Buffer();

	protected:
		unsigned int id;
		BufferType type;
	};

}