#pragma once

#include <assert.h>
#include <glad/glad.h>

#define NATIVE(x) static_cast<GLenum>(x)

namespace lol
{

	/**
	 * @brief OpenGL datatypes
	 */
	enum class Type : GLenum
	{
		Byte			= GL_BYTE,
		UByte			= GL_UNSIGNED_BYTE,
		Short			= GL_UNSIGNED_SHORT,
		Int				= GL_INT,
		UInt			= GL_UNSIGNED_INT,
		Half			= GL_HALF_FLOAT,
		Float			= GL_FLOAT,
		Double			= GL_DOUBLE,
		Fixed			= GL_FIXED
	};

	/**
	 * @brief Get size of OpenGL datatype in Bytes
	 */
	constexpr size_t SizeOf(Type type)
	{
		switch (type)
		{
		case Type::Byte:			return sizeof(GLbyte); 
		case Type::UByte:			return sizeof(GLubyte); 
		case Type::Short:			return sizeof(GLshort); 
		case Type::Int:				return sizeof(GLint); 
		case Type::UInt:			return sizeof(GLuint); 
		case Type::Half:			return sizeof(GLhalf); 
		case Type::Float:			return sizeof(GLfloat); 
		case Type::Double:			return sizeof(GLdouble); 
		case Type::Fixed:			return sizeof(GLfixed);

		default:
			assert(false && "lol::SizeOf did not implement every datatype");
			return 0;
		}
	}

	/**
	 * @brief Datatypes in GLSL
	 */
	enum class GLSLType : GLenum
	{
		Float	= GL_FLOAT,			Float2	= GL_FLOAT_VEC2,				Float3	= GL_FLOAT_VEC3,		Float4	= GL_FLOAT_VEC4,
		Double	= GL_DOUBLE,		Double2	= GL_DOUBLE_VEC2,				Double3 = GL_DOUBLE_VEC3,		Double4 = GL_DOUBLE_VEC4,
		Int		= GL_INT,			Int2	= GL_INT_VEC2,					Int3	= GL_INT_VEC3,			Int4	= GL_INT_VEC4,
		UInt	= GL_UNSIGNED_INT,	UInt2	= GL_UNSIGNED_INT_VEC2,			UInt3	= GL_UNSIGNED_INT_VEC3, UInt4	= GL_UNSIGNED_INT_VEC4,
		Bool	= GL_BOOL,			Bool2	= GL_BOOL_VEC2,					Bool3	= GL_BOOL_VEC3,			Bool4	= GL_BOOL_VEC4,

		Mat2	= GL_FLOAT_MAT2,	Mat3	= GL_FLOAT_MAT3,				Mat4	= GL_FLOAT_MAT4,
		Mat2x3	= GL_FLOAT_MAT2x3,	Mat2x4	= GL_FLOAT_MAT2x4,				Mat3x2	= GL_FLOAT_MAT3x2,		
		Mat3x4	= GL_FLOAT_MAT3x4,	Mat4x2	= GL_FLOAT_MAT4x2,				Mat4x3	= GL_FLOAT_MAT4x3,

		DMat2	= GL_DOUBLE_MAT2,	DMat3	= GL_DOUBLE_MAT3,				DMat4	= GL_DOUBLE_MAT4,
		DMat2x3 = GL_DOUBLE_MAT2x3,	DMat2x4 = GL_DOUBLE_MAT2x4,				DMat3x2	= GL_DOUBLE_MAT3x2,
		DMat3x4 = GL_DOUBLE_MAT3x4,	DMat4x2 = GL_DOUBLE_MAT4x2,				DMat4x3	= GL_DOUBLE_MAT4x3,

		Sampler1D				= GL_SAMPLER_1D,							Sampler2D				= GL_SAMPLER_2D,		
		Sampler3D				= GL_SAMPLER_3D,							SamplerCube				= GL_SAMPLER_CUBE,
		Sampler1DShadow			= GL_SAMPLER_1D_SHADOW,						Sampler2DShadow			= GL_SAMPLER_2D_SHADOW,
		Sampler1DArray			= GL_SAMPLER_1D_ARRAY,						Sampler2DArray			= GL_SAMPLER_2D_ARRAY,
		Sampler1DArrayShadow	= GL_SAMPLER_1D_ARRAY_SHADOW,				Sampler2DArrayShadow	= GL_SAMPLER_2D_ARRAY_SHADOW,
		Sampler2DMS				= GL_SAMPLER_2D_MULTISAMPLE,				Sampler2DMSArray		= GL_SAMPLER_2D_MULTISAMPLE_ARRAY,
		SamplerCubeShadow		= GL_SAMPLER_CUBE_SHADOW,					SamplerBuffer			= GL_SAMPLER_BUFFER,
		Sampler2DRect			= GL_SAMPLER_2D_RECT,						Sampler2DRectShadow		= GL_SAMPLER_2D_RECT_SHADOW,

		ISampler1D				= GL_INT_SAMPLER_1D,						ISampler2D				= GL_INT_SAMPLER_2D,
		ISampler3D				= GL_INT_SAMPLER_3D,						ISamplerCube			= GL_INT_SAMPLER_CUBE,
		ISampler1DArray			= GL_INT_SAMPLER_1D_ARRAY,					ISampler2DArray			= GL_INT_SAMPLER_2D_ARRAY,
		ISampler2DMS			= GL_INT_SAMPLER_2D_MULTISAMPLE,			ISampler2DMSArray		= GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		ISamplerBuffer			= GL_INT_SAMPLER_BUFFER,					ISampler2DRect			= GL_INT_SAMPLER_2D_RECT,

		USampler1D				= GL_UNSIGNED_INT_SAMPLER_1D,				USampler2D				= GL_UNSIGNED_INT_SAMPLER_2D,
		USampler3D				= GL_UNSIGNED_INT_SAMPLER_3D,				USamplerCube			= GL_UNSIGNED_INT_SAMPLER_CUBE,
		USampler1DArray			= GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,			USampler2DArray			= GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,
		USampler2DMS			= GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,	USampler2DMSArray		= GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,
		USamplerBuffer			= GL_UNSIGNED_INT_SAMPLER_BUFFER,			USampler2DRect			= GL_UNSIGNED_INT_SAMPLER_2D_RECT,

		Image1D					= GL_IMAGE_1D,								Image2D					= GL_IMAGE_2D, 
		Image3D					= GL_IMAGE_3D,								Image2DRect				= GL_IMAGE_2D_RECT, 
		ImageCube				= GL_IMAGE_CUBE,							ImageBuffer				= GL_IMAGE_BUFFER,
		Image1DArray			= GL_IMAGE_1D_ARRAY,						Image2DArray			= GL_IMAGE_2D_ARRAY,
		Image2DMS				= GL_IMAGE_2D_MULTISAMPLE,					Image2DMSArray			= GL_IMAGE_2D_MULTISAMPLE_ARRAY,

		IImage1D				= GL_INT_IMAGE_1D,							IImage2D				= GL_INT_IMAGE_2D,
		IImage3D				= GL_INT_IMAGE_3D,							IImage2DRect			= GL_INT_IMAGE_2D_RECT,
		IImageCube				= GL_INT_IMAGE_CUBE,						IImageBuffer			= GL_INT_IMAGE_BUFFER,
		IImage1DArray			= GL_INT_IMAGE_1D_ARRAY,					IImage2DArray			= GL_INT_IMAGE_2D_ARRAY,
		IImage2DMS				= GL_INT_IMAGE_2D_MULTISAMPLE,				IImage2DMSArray			= GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,

		UImage1D				= GL_UNSIGNED_INT_IMAGE_1D,					UImage2D				= GL_UNSIGNED_INT_IMAGE_2D,
		UImage3D				= GL_UNSIGNED_INT_IMAGE_3D,					UImage2DRect			= GL_UNSIGNED_INT_IMAGE_2D_RECT,
		UImageCube				= GL_UNSIGNED_INT_IMAGE_CUBE,				UImageBuffer			= GL_UNSIGNED_INT_IMAGE_BUFFER,
		UImage1DArray			= GL_UNSIGNED_INT_IMAGE_1D_ARRAY,			UImage2DArray			= GL_UNSIGNED_INT_IMAGE_2D_ARRAY,
		UImage2DMS				= GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,		UImage2DMSArray			= GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,

		AtomicUnit = GL_UNSIGNED_INT_ATOMIC_COUNTER
	};

	/**
	 * @brief OpenGL buffer binding targets
	 */
	enum class BufferType : GLenum
	{
		Array				= GL_ARRAY_BUFFER,
		AtomicCounter		= GL_ATOMIC_COUNTER_BUFFER,
		CopyRead			= GL_COPY_READ_BUFFER,
		CopyWrite			= GL_COPY_WRITE_BUFFER,
		DispatchIndirect	= GL_DISPATCH_INDIRECT_BUFFER,
		DrawIndirect		= GL_DRAW_INDIRECT_BUFFER,
		ElementArray		= GL_ELEMENT_ARRAY_BUFFER,
		PixelPack			= GL_PIXEL_PACK_BUFFER,
		PixelUnpack			= GL_PIXEL_UNPACK_BUFFER,
		Query				= GL_QUERY_BUFFER,
		ShaderStorage		= GL_SHADER_STORAGE_BUFFER,
		Texture				= GL_TEXTURE_BUFFER,
		TransformFeedback	= GL_TRANSFORM_FEEDBACK_BUFFER,
		Uniform				= GL_UNIFORM_BUFFER
	};

	/**
	 * @brief OpenGL buffer usage types
	 */
	enum class Usage : GLenum
	{
		StaticDraw	= GL_STATIC_DRAW,
		StaticRead	= GL_STATIC_READ,
		StaticCopy	= GL_STATIC_COPY,

		StreamDraw	= GL_STREAM_DRAW,
		StreamRead	= GL_STREAM_READ,
		StreamCopy	= GL_STREAM_COPY,

		DynamicDraw = GL_DYNAMIC_DRAW,
		DynamicRead = GL_DYNAMIC_READ,
		DynamicCopy = GL_DYNAMIC_COPY
	};

	/**
	 * @brief OpenGL glDraw* modes. Primitives OpenGL can render
	 */
	enum class DrawMode : GLenum
	{
		Points					= GL_POINTS,

		Lines					= GL_LINES,
		LineStrip				= GL_LINE_STRIP,
		LineLoop				= GL_LINE_LOOP,
		LineStripAdjacency		= GL_LINE_STRIP_ADJACENCY,
		LinesAdjacency			= GL_LINES_ADJACENCY,

		Triangles				= GL_TRIANGLES,
		TriangleStrip			= GL_TRIANGLE_STRIP,
		TriangleFan				= GL_TRIANGLE_FAN,
		TriangleStripAdjacency	= GL_TRIANGLE_STRIP_ADJACENCY,
		TrianglesAdjacency		= GL_TRIANGLES_ADJACENCY,

		Patches					= GL_PATCHES
	};

	/**
	 * @brief OpenGL buffer access modes
	 */
	enum class Access : GLenum
	{
		ReadOnly = GL_READ_ONLY,
		WriteOnly = GL_WRITE_ONLY,
		ReadWrite = GL_READ_WRITE
	};
}