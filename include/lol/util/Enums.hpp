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
		Byte			= GL_BYTE,				///< Signed 8 bit integer
		UByte			= GL_UNSIGNED_BYTE,		///< Unsigned 8 bit integer
		Short			= GL_SHORT,				///< Signed 16 bit integer
		UShort			= GL_UNSIGNED_SHORT,	///< Unsigned 16 bit integer
		Int				= GL_INT,				///< Signed 32 bit integer
		UInt			= GL_UNSIGNED_INT,		///< Unsigned 32 bit integer
		Half			= GL_HALF_FLOAT,		///< 16 bit half-precision floating point number
		Float			= GL_FLOAT,				///< 32 bit single-precision floating point number
		Double			= GL_DOUBLE,			///< 64 bit double-precision floating point number
		Fixed			= GL_FIXED				///< 32 bit 16.16 fixed decimal number
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
			assert(false && "lol::SizeOf(Type) did not implement every datatype");
			return 0;
		}
	}

	/**
	 * @brief Datatypes in GLSL
	 */
	enum class GLSLType : GLenum
	{
		Float					= GL_FLOAT,											///< `float`
		Float2					= GL_FLOAT_VEC2,									///< `vec2`	
		Float3					= GL_FLOAT_VEC3,									///< `vec3`
		Float4					= GL_FLOAT_VEC4,									///< `vec4`

		Double					= GL_DOUBLE,										///< `double`
		Double2					= GL_DOUBLE_VEC2,									///< `dvec2`
		Double3 				= GL_DOUBLE_VEC3,									///< `dvec3`
		Double4 				= GL_DOUBLE_VEC4,									///< `dvec4`

		Int						= GL_INT,											///< `int`
		Int2					= GL_INT_VEC2,										///< `ivec2`
		Int3					= GL_INT_VEC3,										///< `ivec3`
		Int4					= GL_INT_VEC4,										///< `ivec4`

		UInt					= GL_UNSIGNED_INT,									///< `uint`
		UInt2					= GL_UNSIGNED_INT_VEC2,								///< `uvec2`
		UInt3					= GL_UNSIGNED_INT_VEC3, 							///< `uvec3`
		UInt4					= GL_UNSIGNED_INT_VEC4,								///< `uvec4`

		Bool					= GL_BOOL,											///< `bool`
		Bool2					= GL_BOOL_VEC2,										///< `bvec2`
		Bool3					= GL_BOOL_VEC3,										///< `bvec3`
		Bool4					= GL_BOOL_VEC4,										///< `bvec4`

		Mat2					= GL_FLOAT_MAT2,									///< `mat2`
		Mat3					= GL_FLOAT_MAT3,									///< `mat3`
		Mat4					= GL_FLOAT_MAT4,									///< `mat4`
		Mat2x3					= GL_FLOAT_MAT2x3,									///< `mat2x3`
		Mat2x4					= GL_FLOAT_MAT2x4,									///< `mat2x4`
		Mat3x2					= GL_FLOAT_MAT3x2,									///< `mat3x2`
		Mat3x4					= GL_FLOAT_MAT3x4,									///< `mat3x4`
		Mat4x2					= GL_FLOAT_MAT4x2,									///< `mat4x2`
		Mat4x3					= GL_FLOAT_MAT4x3,									///< `mat4x3`

		DMat2					= GL_DOUBLE_MAT2,									///< `dmat2`
		DMat3					= GL_DOUBLE_MAT3,									///< `dmat3`
		DMat4					= GL_DOUBLE_MAT4,									///< `dmat4`
		DMat2x3 				= GL_DOUBLE_MAT2x3,									///< `dmat2x3`
		DMat2x4 				= GL_DOUBLE_MAT2x4,									///< `dmat2x4`
		DMat3x2					= GL_DOUBLE_MAT3x2,									///< `dmat3x2`
		DMat3x4 				= GL_DOUBLE_MAT3x4,									///< `dmat3x4`
		DMat4x2 				= GL_DOUBLE_MAT4x2,									///< `dmat4x2`
		DMat4x3					= GL_DOUBLE_MAT4x3,									///< `dmat4x3`

		Sampler1D				= GL_SAMPLER_1D,									///< `sampler1D`			
		Sampler2D				= GL_SAMPLER_2D,									///< `sampler2D`			
		Sampler3D				= GL_SAMPLER_3D,									///< `sampler3D`			
		SamplerCube				= GL_SAMPLER_CUBE,									///< `samplerCube`			
		Sampler1DArray			= GL_SAMPLER_1D_ARRAY,								///< `sampler1DArray`		
		Sampler2DArray			= GL_SAMPLER_2D_ARRAY,								///< `sampler2DArray`		
		Sampler2DMS				= GL_SAMPLER_2D_MULTISAMPLE,						///< `sampler2DMS`			
		Sampler2DMSArray		= GL_SAMPLER_2D_MULTISAMPLE_ARRAY,					///< `sampler2DMSArray`		
		SamplerBuffer			= GL_SAMPLER_BUFFER,								///< `samplerBuffer`		
		Sampler2DRect			= GL_SAMPLER_2D_RECT,								///< `sampler2DRect`		
		Sampler1DShadow			= GL_SAMPLER_1D_SHADOW,								///< `sampler1DShadow`		
		Sampler2DShadow			= GL_SAMPLER_2D_SHADOW,								///< `sampler2DShadow`		
		Sampler1DArrayShadow	= GL_SAMPLER_1D_ARRAY_SHADOW,						///< `sampler1DArrayShadow`	
		Sampler2DArrayShadow	= GL_SAMPLER_2D_ARRAY_SHADOW,						///< `sampler2DArrayShadow`	
		SamplerCubeShadow		= GL_SAMPLER_CUBE_SHADOW,							///< `samplerCubeShadow`	
		Sampler2DRectShadow		= GL_SAMPLER_2D_RECT_SHADOW,						///< `sampler2DRectShadow`	

		ISampler1D				= GL_INT_SAMPLER_1D,								///< `isampler1D`			
		ISampler2D				= GL_INT_SAMPLER_2D,								///< `isampler2D`			
		ISampler3D				= GL_INT_SAMPLER_3D,								///< `isampler3D`			
		ISamplerCube			= GL_INT_SAMPLER_CUBE,								///< `isamplerCube`			
		ISampler1DArray			= GL_INT_SAMPLER_1D_ARRAY,							///< `isampler1DArray`		
		ISampler2DArray			= GL_INT_SAMPLER_2D_ARRAY,							///< `isampler2DArray`		
		ISampler2DMS			= GL_INT_SAMPLER_2D_MULTISAMPLE,					///< `isampler2DMS`			
		ISampler2DMSArray		= GL_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,				///< `isampler2DMSArray`	
		ISamplerBuffer			= GL_INT_SAMPLER_BUFFER,							///< `isamplerBuffer`		
		ISampler2DRect			= GL_INT_SAMPLER_2D_RECT,							///< `isampler2DRect`		
		
		USampler1D				= GL_UNSIGNED_INT_SAMPLER_1D,						///< `usampler1D`
		USampler2D				= GL_UNSIGNED_INT_SAMPLER_2D,						///< `usampler2D`
		USampler3D				= GL_UNSIGNED_INT_SAMPLER_3D,						///< `usampler3D`
		USamplerCube			= GL_UNSIGNED_INT_SAMPLER_CUBE,						///< `usamplerCube`
		USampler1DArray			= GL_UNSIGNED_INT_SAMPLER_1D_ARRAY,					///< `usampler1DArray`
		USampler2DArray			= GL_UNSIGNED_INT_SAMPLER_2D_ARRAY,					///< `usampler2DArray`
		USampler2DMS			= GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE,			///< `usampler2DMS`
		USampler2DMSArray		= GL_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY,		///< `usampler2DMSArray`
		USamplerBuffer			= GL_UNSIGNED_INT_SAMPLER_BUFFER,					///< `usamplerBuffer`
		USampler2DRect			= GL_UNSIGNED_INT_SAMPLER_2D_RECT,					///< `usampler2DRect`
		
		Image1D					= GL_IMAGE_1D,										///< `image1D`		
		Image2D					= GL_IMAGE_2D, 										///< `image2D`		
		Image3D					= GL_IMAGE_3D,										///< `image3D`		
		ImageCube				= GL_IMAGE_CUBE,									///< `imageCube`	
		ImageBuffer				= GL_IMAGE_BUFFER,									///< `imageBuffer`	
		Image1DArray			= GL_IMAGE_1D_ARRAY,								///< `image1DArray`		
		Image2DArray			= GL_IMAGE_2D_ARRAY,								///< `image2DArray`
		Image2DMS				= GL_IMAGE_2D_MULTISAMPLE,							///< `image2DMS`	
		Image2DMSArray			= GL_IMAGE_2D_MULTISAMPLE_ARRAY,					///< `image2DMSArray`	
		Image2DRect				= GL_IMAGE_2D_RECT, 								///< `image2DRect`		

		IImage1D				= GL_INT_IMAGE_1D,									///< `iimage1D`		
		IImage2D				= GL_INT_IMAGE_2D,									///< `iimage2D`		
		IImage3D				= GL_INT_IMAGE_3D,									///< `iimage3D`		
		IImage2DRect			= GL_INT_IMAGE_2D_RECT,								///< `iimageCube`	
		IImageCube				= GL_INT_IMAGE_CUBE,								///< `iimageBuffer`	
		IImageBuffer			= GL_INT_IMAGE_BUFFER,								///< `iimage1DArray`		
		IImage1DArray			= GL_INT_IMAGE_1D_ARRAY,							///< `iimage2DArray`
		IImage2DArray			= GL_INT_IMAGE_2D_ARRAY,							///< `iimage2DMS`	
		IImage2DMS				= GL_INT_IMAGE_2D_MULTISAMPLE,						///< `iimage2DMSArray`	
		IImage2DMSArray			= GL_INT_IMAGE_2D_MULTISAMPLE_ARRAY,				///< `iimage2DRect`		

		UImage1D				= GL_UNSIGNED_INT_IMAGE_1D,							///< `uimage1D`		
		UImage2D				= GL_UNSIGNED_INT_IMAGE_2D,							///< `uimage2D`		
		UImage3D				= GL_UNSIGNED_INT_IMAGE_3D,							///< `uimage3D`		
		UImage2DRect			= GL_UNSIGNED_INT_IMAGE_2D_RECT,					///< `uimageCube`	
		UImageCube				= GL_UNSIGNED_INT_IMAGE_CUBE,						///< `uimageBuffer`	
		UImageBuffer			= GL_UNSIGNED_INT_IMAGE_BUFFER,						///< `uimage1DArray`		
		UImage1DArray			= GL_UNSIGNED_INT_IMAGE_1D_ARRAY,					///< `uimage2DArray`
		UImage2DArray			= GL_UNSIGNED_INT_IMAGE_2D_ARRAY,					///< `uimage2DMS`	
		UImage2DMS				= GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE,				///< `uimage2DMSArray`	
		UImage2DMSArray			= GL_UNSIGNED_INT_IMAGE_2D_MULTISAMPLE_ARRAY,		///< `uimage2DRect`		

		AtomicUnit 				= GL_UNSIGNED_INT_ATOMIC_COUNTER					///< `atomic_uint`
	};

	/**
	 * @brief OpenGL buffer binding targets
	 */
	enum class BufferType : GLenum
	{
		Array				= GL_ARRAY_BUFFER,						///< Vertex attributes
		AtomicCounter		= GL_ATOMIC_COUNTER_BUFFER,				///< Atomic counter storage
		CopyRead			= GL_COPY_READ_BUFFER,					///< Buffer copy source
		CopyWrite			= GL_COPY_WRITE_BUFFER,					///< Buffer copy destination
		DispatchIndirect	= GL_DISPATCH_INDIRECT_BUFFER,			///< Indirect compute dispatch commands
		DrawIndirect		= GL_DRAW_INDIRECT_BUFFER,				///< Indirect command arguments
		ElementArray		= GL_ELEMENT_ARRAY_BUFFER,				///< Vertex array indices
		PixelPack			= GL_PIXEL_PACK_BUFFER,					///< Pixel read target
		PixelUnpack			= GL_PIXEL_UNPACK_BUFFER,				///< Texture data source
		Query				= GL_QUERY_BUFFER,						///< Query result buffer
		ShaderStorage		= GL_SHADER_STORAGE_BUFFER,				///< Read-write storage for shaders
		Texture				= GL_TEXTURE_BUFFER,					///< Texture data buffer
		TransformFeedback	= GL_TRANSFORM_FEEDBACK_BUFFER,			///< Transform feedback buffer
		Uniform				= GL_UNIFORM_BUFFER						///< Uniform block storage
	};

	/**
	 * @brief OpenGL buffer usage types
	 */
	enum class Usage : GLenum
	{
		StaticDraw	= GL_STATIC_DRAW,		///< Data is only written, and is only modified once
		StaticRead	= GL_STATIC_READ,		///< Data is only read, and is only modified once
		StaticCopy	= GL_STATIC_COPY,		///< Data is never written or read, and is only modified once

		StreamDraw	= GL_STREAM_DRAW,		///< Data is only written, and is modified after every use
		StreamRead	= GL_STREAM_READ,		///< Data is only read, and is modified after every use
		StreamCopy	= GL_STREAM_COPY,		///< Data is never written or read, and is modified after every use

		DynamicDraw = GL_DYNAMIC_DRAW,		///< Data is only written, and is modified occasionally
		DynamicRead = GL_DYNAMIC_READ,		///< Data is only read, and is modified occasionally
		DynamicCopy = GL_DYNAMIC_COPY		///< Data is never written or read, and is modified occasionally
	};

	/**
	 * @brief OpenGL glDraw* modes. Primitives OpenGL can render
	 */
	enum class DrawMode : GLenum
	{
		Points					= GL_POINTS,						///< Render vertices as individual points

		Lines					= GL_LINES,							///< Render pairs of vertices as individual lines (0 and 1 are a line, 2 and 3 are a line, etc)
		LineStrip				= GL_LINE_STRIP,					///< Render consecutive vertices as connected lines (0 and 1 are a line, 1 and 2 are a line, etc)
		LineLoop				= GL_LINE_LOOP,						///< Similar to DrawMode::LineStrip, but the first and last vertex are also connected
		LineStripAdjacency		= GL_LINE_STRIP_ADJACENCY,			///< Allow geometry shaders to access vertex data of adjacent lines
		LinesAdjacency			= GL_LINES_ADJACENCY,				///< Allow geometry shaders to access vertex data of adjacent lines

		Triangles				= GL_TRIANGLES,						///< Render triplets of vertices as individual triangles (0, 1, 2 are a triangle, 3, 4, 5 are a triangle, etc)
		TriangleStrip			= GL_TRIANGLE_STRIP,				///< Every triplet of vertices is a triangle (0, 1, 2 are a triangle, 1, 2, 3 are a triangle, etc)
		TriangleFan				= GL_TRIANGLE_FAN,					///< Every pair of vertices forms a triangle with the first vertex (0, 1, 2 is a triangle, 0, 2, 3 is a triangle, etc)
		TriangleStripAdjacency	= GL_TRIANGLE_STRIP_ADJACENCY,		///< Allow geometry shaders to access vertex data of adjacent triangles
		TrianglesAdjacency		= GL_TRIANGLES_ADJACENCY,			///< Allow geometry shaders to access vertex data of adjacent triangles

		Patches					= GL_PATCHES						///< Used for tesselation
	};

	/**
	 * @brief OpenGL buffer access modes
	 */
	enum class Access : GLenum
	{
		ReadOnly = GL_READ_ONLY,			///< Read-only access
		WriteOnly = GL_WRITE_ONLY,			///< Write-only access
		ReadWrite = GL_READ_WRITE			///< Read-Write access
	};

	/** 
	 * @brief OpenGL target texture
	 */
	enum class TargetTexture : GLenum
	{
		Texture1D 		= GL_TEXTURE_1D,						///< A single 1D Texture (Image has only width)
		Texture2D 		= GL_TEXTURE_2D,						///< A single 2D Texture (Image has width and height)
		Texture3D 		= GL_TEXTURE_3D,						///< A single 3D Texture (Image has width, height and depth)
		Array1D 		= GL_TEXTURE_1D_ARRAY,					///< Multiple 1D Textures stored in one Texture
		Array2D 		= GL_TEXTURE_2D_ARRAY,					///< Multiple 2D Textures stored in one Texture
		Rectangle 		= GL_TEXTURE_RECTANGLE,					///< A single 2D Texture, texture coordinates are not normalized
		Cubemap 		= GL_TEXTURE_CUBE_MAP,					///< A single Cubemap (6 distinct sets of 2D square-shaped images of the same size)
		CubemapArray 	= GL_TEXTURE_CUBE_MAP_ARRAY,			///< Multiple Cubemaps stored in one Texture
		Buffer 			= GL_TEXTURE_BUFFER,					///< A single 1D Texture, the data comes from a Buffer
		Multisample 	= GL_TEXTURE_2D_MULTISAMPLE,			///< A single 2D Texture, each pixel contains multiple samples instead of one
		MultisampleArra = GL_TEXTURE_2D_MULTISAMPLE_ARRAY		///< Multiple multisampled Textures
	};

	/**
	 * @brief OpenGL internal texture formats
	 */
	enum class TextureFormat : GLenum
	{
		DepthComponent	= GL_DEPTH_COMPONENT,							///< Texture stores depth information
		DepthStencil	= GL_DEPTH_STENCIL,								///< Texture stores depth and stencil information
		R				= GL_RED,										///< 1 channel, unsigned normalized integer
		RG				= GL_RG,										///< 2 channels, unsigned normalized integers, OpenGL chooses the bitdepth
		RGB				= GL_RGB,										///< 3 channels, unsigned normalized integers, OpenGL chooses the bitdepth
		RGBA			= GL_RGBA,										///< 4 channels, unsigned normalized integers, OpenGL chooses the bitdepth
		R8				= GL_R8,										///< 1 channel, unsigned normalized integers, 8 bits per channel
		R8S				= GL_R8_SNORM,									///< 1 channel, signed normalized integers, 8 bits per channel
		R16				= GL_R16,										///< 1 channel, unsigned normalized integers, 16 bits per channel
		R16S			= GL_R16_SNORM,									///< 1 channel, signed normalized integers, 16 bits per channel
		RG8				= GL_RG8,										///< 2 channels, unsigned normalized integers, 8 bits per channel
		RG8S			= GL_RG8_SNORM, 								///< 2 channels, signed normalized integers, 8 bits per channel
		RG16			= GL_RG16,										///< 2 channels, unsigned normalized integers, 16 bits per channel
		RG16S			= GL_RG16_SNORM,								///< 2 channels, signed normalized integers, 16 bits per channel
		R3G3B2			= GL_R3_G3_B2,									///< 3 channels, unsigned normalized integers, 3 bits for R and G, 2 bits for B
		RGB4			= GL_RGB4,										///< 3 channels, unsigned normalized integers, 4 bits per channel
		RGB5			= GL_RGB5,										///< 3 channels, unsigned normalized integers, 5 bits per channel
		RGB8			= GL_RGB8,										///< 3 channels, unsigned normalized integers, 8 bits per channel
		RGB8S			= GL_RGB8_SNORM,								///< 3 channels, signed normalized integers, 8 bits per channel
		RGB10			= GL_RGB10,										///< 3 channels, unsigned normalized integers, 10 bits per channel
		RGB12			= GL_RGB12,										///< 3 channels, unsigned normalized integers, 12 bits per channel
		RGB16S			= GL_RGB16_SNORM,								///< 3 channels, signed normalized integers, 16 bits per channel
		RGBA2			= GL_RGBA2,										///< 4 channels, unsigned normalized integers, 2 bits per channel
		RGBA4			= GL_RGBA4,										///< 4 channels, unsigned normalized integers, 4 bits per channel
		RGB5A1			= GL_RGB5_A1,									///< 4 channels, unsigned normalized integers, 5 bits for R, G and B, 1 bit for A
		RGBA8			= GL_RGBA8,										///< 4 channels, unsigned normalized integers, 8 bits per channel
		RGBA8S			= GL_RGBA8_SNORM,								///< 4 channels, signed normalized integers, 8 bits per channel
		RGB10A2 		= GL_RGB10_A2,									///< 4 channels, unsigned normalized integers, 10 bits for R, G and B, 2 bits for A
		RGB10A2UI		= GL_RGB10_A2UI,								///< 4 channels, unsigned integers, 10 bits for R, G and B, 2 bits for A
		RGBA12			= GL_RGBA12,									///< 4 channels, unsigned normalized integers, 12 bits per channel
		RGBA16			= GL_RGBA16,									///< 4 channels, unsigned normalized integers, 16 bits per channel
		SRGB8			= GL_SRGB8,										///< 3 sRGB channels, unsigned normalized integers, 8 bits per channel
		SRGB8A8			= GL_SRGB8_ALPHA8,								///< 4 sRGB channels, unsigned normalized integers, 8 bits per channel
		R16F			= GL_R16F,										///< 1 channel, floating points, 16 bits per channel
		RG16F			= GL_RG16F,										///< 2 channels, floating points, 16 bits per channel
		RGB16F			= GL_RGB16F,									///< 3 channels, floating points, 16 bits per channel
		RGBA16F			= GL_RGBA16F,									///< 4 channels, floating points, 16 bits per channel
		R32F			= GL_R32F,										///< 1 channel, floating points, 32 bits per channel
		RG32F			= GL_RG32F,										///< 2 channels, floating points, 32 bits per channel
		RGB32F			= GL_RGB32F,									///< 3 channels, floating points, 32 bits per channel
		RGBA32F			= GL_RGBA32F,									///< 4 channels, floating points, 32 bits per channel
		R11FG11FB10F	= GL_R11F_G11F_B10F,							///< 3 channels, floating points, 11 bits for R and G, 10 bits for B
		RGB9E5			= GL_RGB9_E5,									///< 3 channels, floating points, 9 bits per channel, all channels share the same exponent
		R8I				= GL_R8I,										///< 1 channel, signed integers, 8 bits per channel
		R8UI			= GL_R8UI,										///< 1 channel, unsigned integers, 8 bits per channel
		R16I			= GL_R16I,										///< 1 channel, signed integers, 16 bits per channel
		R16UI			= GL_R16UI,										///< 1 channel, unsigned integers, 16 bits per channel
		R32I			= GL_R32I,										///< 1 channel, signed integers, 32 bits per channel
		R32UI			= GL_R32UI,										///< 1 channel, unsigned integers, 16 bits per channel
		RG8I			= GL_RG8I,										///< 2 channels, signed integers, 8 bits per channel
		RG8UI			= GL_RG8UI,										///< 2 channels, unsigned integers, 8 bits per channel
		RG16I			= GL_RG16I,										///< 2 channels, signed integers, 16 bits per channel
		RG16UI			= GL_RG16UI,									///< 2 channels, unsigned integers, 16 bits per channel
		RG32I			= GL_RG32I,										///< 2 channels, signed integers, 32 bits per channel
		RG32UI			= GL_RG32UI,									///< 2 channels, unsigned integers, 16 bits per channel
		RGB8I			= GL_RGB8I,										///< 3 channels, signed integers, 8 bits per channel
		RGB8UI			= GL_RGB8UI,									///< 3 channels, unsigned integers, 8 bits per channel
		RGB16I			= GL_RGB16I,									///< 3 channels, signed integers, 16 bits per channel
		RGB16UI			= GL_RGB16UI,									///< 3 channels, unsigned integers, 16 bits per channel
		RGB32I			= GL_RGB32I,									///< 3 channels, signed integers, 32 bits per channel
		RGB32UI			= GL_RGB32UI,									///< 3 channels, unsigned integers, 16 bits per channel
		RGBA8I			= GL_RGBA8I,									///< 4 channels, signed integers, 8 bits per channel
		RGBA8UI			= GL_RGBA8UI,									///< 4 channels, unsigned integers, 8 bits per channel
		RGBA16I			= GL_RGBA16I,									///< 4 channels, signed integers, 16 bits per channel
		RGBA16UI		= GL_RGBA16UI,									///< 4 channels, unsigned integers, 16 bits per channel
		RGBA32I			= GL_RGBA32I,									///< 4 channels, signed integers, 32 bits per channel
		RGBA32UI		= GL_RGBA32UI,									///< 4 channels, unsigned integers, 16 bits per channel
		CR				= GL_COMPRESSED_RED,							///< 1 channel, unsigned normalized integers, compressed
		CRG				= GL_COMPRESSED_RG,								///< 2 channels, unsigned normalized integers, compressed
		CRGB			= GL_COMPRESSED_RGB,							///< 3 channels, unsigned normalized integers, compressed
		CRGBA			= GL_COMPRESSED_RGBA,							///< 4 channels, unsigned normalized integers, compressed
		CSRGB			= GL_COMPRESSED_SRGB,							///< 3 sRGB channels, unsigned normalized integers, compressed 
		CSRGBA			= GL_COMPRESSED_SRGB_ALPHA,						///< 4 sRGB channels, unsigned normalized integers, compressed
		CR_RGTC1		= GL_COMPRESSED_RED_RGTC1,						///< 1 channel, unsigned normalized integers, red/green compressed
		CRS_RGTC1		= GL_COMPRESSED_SIGNED_RED_RGTC1,				///< 1 channel, signed normalized integers, red/green compressed
		CRG_RGTC2		= GL_COMPRESSED_RG_RGTC2,						///< 2 channels, unsigned normalized integers, red/green compressed
		CRGS_RGTC2		= GL_COMPRESSED_SIGNED_RG_RGTC2,				///< 2 channels, signed normalized integers, red/green compressed
		CRGBA_BPTC		= GL_COMPRESSED_RGBA_BPTC_UNORM,				///< 4 channels, unsigned normalized integers, BPTC compressed
		CSRGBA_BPTC		= GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,			///< 4 sRGB channels, unsigned normalized integers, BPTC compressed
		CRGB_BPTC_SF	= GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,			///< 3 channels, signed floating points, BPTC compressed
		CRGB_BPTC_UF	= GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,		///< 3 channels, unsigned floating points, BPTC compressed
	};	

	/**
	 * @brief OpenGL internal pixel formats
	 */
	enum class PixelFormat : GLenum
	{
		R				= GL_RED,					///< R
		RG				= GL_RG,					///< RG
		RGB				= GL_RGB,					///< RGB
		BGR				= GL_BGR,					///< BGR
		RGBA			= GL_RGBA,					///< RGBA
		BGRA			= GL_BGRA,					///< BGRA
		RI				= GL_RED_INTEGER,			///< R, integer values
		RGI				= GL_RG_INTEGER,			///< RG, integer values
		RGBI			= GL_RGB_INTEGER,			///< RGB, integer values
		BGRI			= GL_BGR_INTEGER,			///< BGR, integer values
		RGBAI			= GL_RGBA_INTEGER,			///< RGBA, integer values
		BGRAI			= GL_BGRA_INTEGER,			///< BGRA, integer values
		StencilIndex	= GL_STENCIL_INDEX,			///< Depth stencil indexed
		DepthComponent	= GL_DEPTH_COMPONENT,		///< Depth values (range [0, 1])
		DepthStencil	= GL_DEPTH_STENCIL,			///< Depth, Stencil pairs
	};

	/**
	 * @brief OpenGL Pixel datatypes
	 */
	enum class PixelType : GLenum
	{
		UByte			= GL_UNSIGNED_BYTE,						///< All channels are unsigned bytes	
		Byte			= GL_BYTE,								///< All channels are signed bytes	
		UShort			= GL_UNSIGNED_SHORT,					///< All channels are unsigned shorts	
		Short			= GL_SHORT,								///< All channels are signed bytes	
		UInt			= GL_UNSIGNED_INT,						///< All channels are unsigned integers	
		Int				= GL_INT,								///< All channels are signed integers	
		Float			= GL_FLOAT,								///< All channels are floating points

		UByte332		= GL_UNSIGNED_BYTE_3_3_2,				///< R = 3 Bits, G = 3 Bits, B = 2 Bits (RGB)
		UByte233Rev		= GL_UNSIGNED_BYTE_2_3_3_REV,			///< R = 3 Bits, G = 3 Bits, B = 2 Bits (BGR)
		UShort565		= GL_UNSIGNED_SHORT_5_6_5,				///< R = 5 Bits, G = 6 Bits, B = 5 Bits (RGB)
		UShort565Rev	= GL_UNSIGNED_SHORT_5_6_5_REV,			///< R = 5 Bits, G = 6 Bits, B = 5 Bits (BGR)
		UShort4444		= GL_UNSIGNED_SHORT_4_4_4_4,			///< R = 4 Bits, G = 4 Bits, B = 4 Bits, A = 4 Bits (RGBA)
		UShort4444Rev	= GL_UNSIGNED_SHORT_4_4_4_4_REV,		///< R = 4 Bits, G = 4 Bits, B = 4 Bits, A = 4 Bits (ABGR)
		UShort5551		= GL_UNSIGNED_SHORT_5_5_5_1,			///< R = 5 Bits, G = 5 Bits, B = 5 Bits, A = 1 Bits (RGBA)
		UShort1555Rev	= GL_UNSIGNED_SHORT_1_5_5_5_REV,		///< R = 5 Bits, G = 5 Bits, B = 5 Bits, A = 1 Bits (ABGR)
		UInt8888		= GL_UNSIGNED_INT_8_8_8_8,				///< R = 8 Bits, G = 8 Bits, B = 8 Bits, A = 8 Bits (RGBA)
		UInt8888Rev		= GL_UNSIGNED_INT_8_8_8_8_REV,			///< R = 8 Bits, G = 8 Bits, B = 8 Bits, A = 8 Bits (ABGR)
		UInt1010102		= GL_UNSIGNED_INT_10_10_10_2,			///< R = 10 Bits, G = 10 Bits, B = 10 Bits, A = 10 Bits (RGBA)
		UInt1010102Rev	= GL_UNSIGNED_INT_2_10_10_10_REV		///< R = 10 Bits, G = 10 Bits, B = 10 Bits, A = 10 Bits (ABGR)
	};

	/**
	 * @brief Get size of OpenGL datatype in Bytes
	 */
	constexpr size_t SizeOf(PixelType type)
	{
		switch (type)
		{
		case PixelType::UByte332:
		case PixelType::UByte233Rev:
		case PixelType::Byte:			
			return sizeof(GLbyte);

		case PixelType::UByte:			
			return sizeof(GLubyte);

		case PixelType::Short:
			return sizeof(GLshort);

		case PixelType::UShort565:
		case PixelType::UShort565Rev:
		case PixelType::UShort4444:
		case PixelType::UShort4444Rev:
		case PixelType::UShort5551:
		case PixelType::UShort1555Rev:
		case PixelType::UShort:
			return sizeof(GLushort);

		case PixelType::Int:			
			return sizeof(GLint);

		case PixelType::UInt8888:
		case PixelType::UInt8888Rev:
		case PixelType::UInt1010102:
		case PixelType::UInt1010102Rev:
		case PixelType::UInt:			
			return sizeof(GLuint);

		case PixelType::Float:			
			return sizeof(GLfloat);

		default:
			assert(false && "lol::SizeOf(PixelType) did not implement every datatype");
			return 0;
		}
	}

	enum class TextureWrap : GLenum
	{
		ClampToEdge 		= GL_CLAMP_TO_EDGE,				///< Pixels outside of texture get the textures edge color
		ClampToBorder		= GL_CLAMP_TO_BORDER,			///< Pixels outside of texture get the border color
		MirroredRepeat 		= GL_MIRRORED_REPEAT,			///< Texture is mirrored and repeated
		Repeat 				= GL_REPEAT,					///< Texture is repeated
		MirrorClampToEdge 	= GL_MIRROR_CLAMP_TO_EDGE		///< Texture is mirrored once and then clamped
	};
}