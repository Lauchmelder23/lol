#pragma once

#include <glad/glad.h>

#include <lol/Shader.hpp>
#include <lol/VertexArrayObject.hpp>

namespace lol
{

	class CameraBase;

	enum class PrimitiveType
	{
		Lines = GL_LINES,
		LineStrip = GL_LINE_STRIP,
		LineLoop = GL_LINE_LOOP,

		Triangles = GL_TRIANGLES,
		TriangleStrip = GL_TRIANGLE_STRIP,
		TriangleFan = GL_TRIANGLE_FAN
	};

	/**
	 * A class that can be displayed on a screen.
	 */
	class Drawable
	{
	public:
		/**
		 * @brief Called immediately after the shader is bound, and before the VAO is drawn.
		 * 
		 * @param camera The camera with which this object is rendered.
		 */
		virtual void PreRender(const CameraBase& camera) const { };

		/**
		 * @brief Bind the shader and draw the VAO
		 * 
		 * @param camera The camera with which this object is rendered.
		 */
		void Draw(const CameraBase& camera) const;

		/**
		 * @brief The VAO can be rendered as a mesh, a set of lines, loops, strips etc
		 */
		void SetPrimitiveType(PrimitiveType type);

	protected:
		Drawable() {}

	protected:
		VertexArrayObject vao;
		Shader shader;

		PrimitiveType type = PrimitiveType::Triangles;
	};

}