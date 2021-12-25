#pragma once

#include <glad/glad.h>

#include <lol/Shader.hpp>
#include <lol/VertexArrayObject.hpp>

namespace lol
{

	class CameraBase;

	/**
	 * A class that can be displayed on a screen.
	 */
	class Drawable
	{
	public:
		virtual ~Drawable() {}

		/**
		 * @brief Called immediately after the shader is bound, and before the VAO is drawn.
		 * 
		 * @param camera The camera with which this object is rendered.
		 */
		virtual void PreRender(const CameraBase& camera) { };

		/**
		 * @brief Bind the shader and draw the VAO
		 * 
		 * @param camera The camera with which this object is rendered.
		 */
		void Draw(const CameraBase& camera);

		/**
		 * @brief The VAO can be rendered as a mesh, a set of lines, loops, strips etc
		 */
		void SetDrawMode(DrawMode type);

	protected:
		Drawable() {}

	protected:
		std::shared_ptr<VertexArray> vao;
		std::shared_ptr<Shader> shader;

		DrawMode type = DrawMode::Triangles;
	};

}