#pragma once

#include <vector>
#include <memory>

#include <lol/buffers/VertexBuffer.hpp>
#include <lol/buffers/ElementBuffer.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{
	/**
	 * VAO structure that sets up the buffers and deletes them at the end of the lifecycle
	 */ 
	class VertexArray : public NonCopyable
	{
	public:
		/**
		 * @brief Creates new VAO from a set of vertices and indices and a layout/usage description
		 */
		VertexArray();
		VertexArray(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<ElementBuffer>& elementBuffer);
		virtual ~VertexArray();

		void SetElementBuffer(const std::shared_ptr<ElementBuffer>& buffer);
		void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);

		void Bind();
		void Unbind();

		inline size_t GetIndexCount() { return elementBuffer->GetCount(); }

	private:
		unsigned int id;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ElementBuffer> elementBuffer;
	};

	// Object manager for managing said shared pointers
	typedef ObjectManager<VertexArray> VAOManager;

}