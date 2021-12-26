#pragma once

#include <vector>
#include <memory>

#include <lol/buffers/VertexBuffer.hpp>
#include <lol/buffers/ElementBuffer.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{
	/**
	 * @brief VAO structure that sets up the buffers and deletes them at the end of the lifecycle
	 */ 
	class VertexArray : public NonCopyable
	{
	public:
		/**
		 * @brief Creates new VAO without binding any buffers and without setting up attribute pointers
		 */
		VertexArray();

		/**
		 * @brief Construct a new VAO, binds the given buffers and sets up the attribute pointers
		 * 
		 * @param vertexBuffer 	The VBO to bind to the VAO
		 * @param elementBuffer The EBO to bind to the VAO
		 */
		VertexArray(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<ElementBuffer>& elementBuffer);
		
		virtual ~VertexArray();

		/**
		 * @brief Set the EBO the VAO should use for rendering
		 * 
		 * @param buffer The index buffer that will be rendered
		 */
		void SetElementBuffer(const std::shared_ptr<ElementBuffer>& buffer);

		/**
		 * @brief Set the VBO the EBO is indexing
		 * 
		 * @param buffer The vertex buffer that is being indexed in the VAO
		 */
		void SetVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer);

		/**
		 * @brief Binds the VAO
		 */
		void Bind();

		/**
		 * @brief Unbinds the VAO
		 */
		void Unbind();

		/**
		 * @brief Returns the number of indices inside the element buffer
		 * 
		 * @return Number of elements in the EBO
		 */
		inline size_t GetIndexCount() { return elementBuffer->GetCount(); }

	private:
		unsigned int id;
		std::shared_ptr<VertexBuffer> vertexBuffer;
		std::shared_ptr<ElementBuffer> elementBuffer;
	};

}