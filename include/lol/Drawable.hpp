#pragma once

#include <glad/glad.h>

#include <lol/NonCopyable.hpp>
#include <lol/Shader.hpp>

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

	class Drawable
	{
	public:
		virtual void PreRender(const CameraBase& camera) const { };
		void Draw(const CameraBase& camera) const;
		void SetPrimitiveType(PrimitiveType type);

	protected:
		Drawable() {}

	protected:
		VertexArrayObject vao;
		Shader shader;

		PrimitiveType type = PrimitiveType::Triangles;
	};

}