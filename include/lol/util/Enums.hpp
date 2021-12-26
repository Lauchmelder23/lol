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

	/** 
	 * @brief OpenGL target texture
	 */
	enum class TargetTexture : GLenum
	{
		Texture1D 		= GL_TEXTURE_1D,
		Texture2D 		= GL_TEXTURE_2D,
		Texture3D 		= GL_TEXTURE_3D,
		Array1D 		= GL_TEXTURE_1D_ARRAY,
		Array2D 		= GL_TEXTURE_2D_ARRAY,
		Rectangle 		= GL_TEXTURE_RECTANGLE,
		Cubemap 		= GL_TEXTURE_CUBE_MAP,
		CubemapArray 	= GL_TEXTURE_CUBE_MAP_ARRAY,
		Buffer 			= GL_TEXTURE_BUFFER,
		Multisample 	= GL_TEXTURE_2D_MULTISAMPLE,
		MultisampleArra = GL_TEXTURE_2D_MULTISAMPLE_ARRAY
	};

	/**
	 * @brief OpenGL internal texture formats
	 */
	enum class TextureFormat : GLenum
	{
		DepthComponent	= GL_DEPTH_COMPONENT,
		DepthStencil	= GL_DEPTH_STENCIL,
		R				= GL_RED,
		RG				= GL_RG,
		RGB				= GL_RGB,
		RGBA			= GL_RGBA,

		R8				= GL_R8,			R8S		= GL_R8_SNORM,	R16			= GL_R16,			R16S			= GL_R16_SNORM,
		RG8				= GL_RG8,			RG8S	= GL_RG8_SNORM, RG16		= GL_RG16,			RG16S			= GL_RG16_SNORM,
		R3G3B2			= GL_R3_G3_B2,		RGB4	= GL_RGB4,		RGB5		= GL_RGB5,			RGB8			= GL_RGB8,
		RGB8S			= GL_RGB8_SNORM,	RGB10	= GL_RGB10,		RGB12		= GL_RGB12,			RGB16S			= GL_RGB16_SNORM,
		RGBA2			= GL_RGBA2,			RGBA4	= GL_RGBA4,		RGB5A1		= GL_RGB5_A1,		RGBA8			= GL_RGBA8,
		RGBA8S			= GL_RGBA8_SNORM,	RGB10A2 = GL_RGB10_A2,	RGB10A2UI	= GL_RGB10_A2UI,	RGBA12			= GL_RGBA12,
		RGBA16			= GL_RGBA16,		SRGB8	= GL_SRGB8,		SRGB8A8		= GL_SRGB8_ALPHA8,	R16F			= GL_R16F,
		RG16F			= GL_RG16F,			RGB16F	= GL_RGB16F,	RGBA16F		= GL_RGBA16F,		R32F			= GL_R32F,
		RG32F			= GL_RG32F,			RGB32F	= GL_RGB32F,	RGBA32F		= GL_RGBA32F,		R11FG11FB10F	= GL_R11F_G11F_B10F,
		RGB9E5			= GL_RGB9_E5,		R8I		= GL_R8I,		R8UI		= GL_R8UI,			R16I			= GL_R16I,
		R16UI			= GL_R16UI,			R32I	= GL_R32I,		R32UI		= GL_R32UI,			RG8I			= GL_RG8I,
		RG8UI			= GL_RG8UI,			RG16I	= GL_RG16I,		RG16UI		= GL_RG16UI,		RG32I			= GL_RG32I,
		RG32UI			= GL_RG32UI,		RGB8I	= GL_RGB8I,		RGB8UI		= GL_RGB8UI,		RGB16I			= GL_RGB16I,
		RGB16UI			= GL_RGB16UI,		RGB32I	= GL_RGB32I,	RGB32UI		= GL_RGB32UI,		RGBA8I			= GL_RGBA8I,
		RGBA8UI			= GL_RGBA8UI,		RGBA16I	= GL_RGBA16I,	RGBA16UI	= GL_RGBA16UI,		RGBA32I			= GL_RGBA32I,
		RGBA32UI		= GL_RGBA32UI,

		CR				= GL_COMPRESSED_RED,
		CRG				= GL_COMPRESSED_RG,
		CRGB			= GL_COMPRESSED_RGB,
		CRGBA			= GL_COMPRESSED_RGBA,
		CSRGB			= GL_COMPRESSED_SRGB,
		CSRGBA			= GL_COMPRESSED_SRGB_ALPHA,
		CR_RGTC1		= GL_COMPRESSED_RED_RGTC1,
		CRS_RGTC1		= GL_COMPRESSED_SIGNED_RED_RGTC1,
		CRG_RGTC2		= GL_COMPRESSED_RG_RGTC2,
		CRGS_RGTC2		= GL_COMPRESSED_SIGNED_RG_RGTC2,
		CRGBA_BPTC		= GL_COMPRESSED_RGBA_BPTC_UNORM,
		CSRGBA_BPTC		= GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM,
		CRGB_BPTC_SF	= GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT,
		CRGB_BPTC_UF	= GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT,
	};

	/**
	 * @brief OpenGL internal pixel formats
	 */
	enum class PixelFormat : GLenum
	{
		R				= GL_RED,
		RG				= GL_RG,
		RGB				= GL_RGB,
		BGR				= GL_BGR,
		RGBA			= GL_RGBA,
		BGRA			= GL_BGRA,
		RI				= GL_RED_INTEGER,
		RGI				= GL_RG_INTEGER,
		RGBI			= GL_RGB_INTEGER,
		BGRI			= GL_BGR_INTEGER,
		RGBAI			= GL_RGBA_INTEGER,
		BGRAI			= GL_BGRA_INTEGER,
		StencilIndex	= GL_STENCIL_INDEX,
		DepthComponent	= GL_DEPTH_COMPONENT,
		DepthStencil	= GL_DEPTH_STENCIL,
	};

	/**
	 * @brief OpenGL Pixel datatypes
	 */
	enum class PixelType : GLenum
	{
		UByte		= GL_UNSIGNED_BYTE,				Byte			= GL_BYTE,
		UShort		= GL_UNSIGNED_SHORT,			Short			= GL_SHORT,
		UInt		= GL_UNSIGNED_INT,				Int				= GL_INT,
		Float		= GL_FLOAT,

		UByte332	= GL_UNSIGNED_BYTE_3_3_2,		UByte233Rev		= GL_UNSIGNED_BYTE_2_3_3_REV,
		UShort565	= GL_UNSIGNED_SHORT_5_6_5,		UShort565Rev	= GL_UNSIGNED_SHORT_5_6_5_REV,
		UShort4444	= GL_UNSIGNED_SHORT_4_4_4_4,	UShort4444Rev	= GL_UNSIGNED_SHORT_4_4_4_4_REV,
		UShort5551	= GL_UNSIGNED_SHORT_5_5_5_1,	UShort1555Rev	= GL_UNSIGNED_SHORT_1_5_5_5_REV,
		UInt8888	= GL_UNSIGNED_INT_8_8_8_8,		UInt8888Rev		= GL_UNSIGNED_INT_8_8_8_8_REV,
		UInt1010102	= GL_UNSIGNED_INT_10_10_10_2,	UInt1010102Rev	= GL_UNSIGNED_INT_2_10_10_10_REV
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
		ClampToEdge = GL_CLAMP_TO_EDGE,
		ClampToBorder = GL_CLAMP_TO_BORDER,
		MirroredRepeat = GL_MIRRORED_REPEAT,
		Repeat = GL_REPEAT,
		MirrorClampToEdge = GL_MIRROR_CLAMP_TO_EDGE
	};
}