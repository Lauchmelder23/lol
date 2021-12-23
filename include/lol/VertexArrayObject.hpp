#pragma once

#include <vector>
#include <memory>

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{

	/**
	 * Struct representing an OpenGL attribute pointer
	 */
	struct VertexAttribute
	{
		int				size;
		unsigned int	type;
		bool			normalized;
		unsigned int	stride;
		const void*		pointer;
	};

	// Useful abbreviations
	typedef std::vector<float>				VertexArray;
	typedef std::vector<unsigned int>		IndexArray;
	typedef std::vector<VertexAttribute>	Layout;


	// OpenGL Buffer usages (I turned them into an enum so it's easier to know what options exist)
	enum class Usage
	{
		Static, Stream, Dynamic
	};

	class UniqueVertexArrayObject;
	// You cannot actually create this VAO, you are forced to use a shared pointer
	// so the buffers dont get accidentally deleted while another obejct is potentially still using it.
	// I find this to be very important since VAOs are supposed to be shared between copies of objects
	// if they have the same model.
	typedef std::shared_ptr<UniqueVertexArrayObject> VertexArrayObject;

	/**
	 * VAO structure that sets up the buffers and deletes them at the end of the lifecycle
	 */ 
	class UniqueVertexArrayObject : public NonCopyable
	{
	public:
		/**
		 * @brief Creates new VAO from a set of vertices and indices and a layout/usage description
		 * 
		 * @param vertices	The vertices to go into the array buffer
		 * @param indices	The indices to go into the element array buffer
		 * @param layout	The layout of the VAO
		 * @param usage		Usage of the VAO (static, dynamic, stream)
		 */
		UniqueVertexArrayObject(const VertexArray& vertices, const IndexArray& indices, const Layout& layout, Usage usage = Usage::Static);
		~UniqueVertexArrayObject();

		/**
		 * @brief Creates a shareable UniqueVertexArrayObject. Note that they're SHAREable, not COPYable
		 *
		 * @param vertices	The vertices to go into the array buffer
		 * @param indices	The indices to go into the element array buffer
		 * @param layout	The layout of the VAO
		 * @param usage		Usage of the VAO (static, dynamic, stream)
		 *
		 * @returns Shared pointer to a UniqueVertexArrayObject
		 */
		inline static VertexArrayObject Share(const VertexArray& vertices, const IndexArray& indices, const Layout& layout, Usage usage = Usage::Static)
		{
			return std::make_shared<UniqueVertexArrayObject>(vertices, indices, layout, usage);
		}

		/**
		 * @brief Render the VAO
		 * 
		 * @param mode The render mode (lines, triangles, ...)
		 */
		void Render(unsigned int mode = 4);

	private:
		unsigned int vao, vbo, ebo;
		size_t indexCount;
	};

	// Object manager for managing said shared pointers
	typedef ObjectManager<VertexArrayObject> VAOManager;

}