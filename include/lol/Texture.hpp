#pragma once

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	class Image;

	/**
	 * @brief A generic OpenGL Texture
	 * 
	 * This class is a *generic* texture object. It can represent *any* kind of OpenGL Texture.
	 * Consider using its derived classes (e.g. Texture1D, Texture2D, ...)
	 */
	class Texture : public NonCopyable
	{
	public:
		/**
		 * @brief Generate a new Texture of the specified target
		 * 
		 * @param target The target of the Texture 
		 */
		Texture(TargetTexture target);
		~Texture();

		/**
		 * @brief Bind the Texture
		 * 
		 */
		void Bind();

		/**
		 * @brief Unbind the Texture
		 * 
		 */
		void Unbind();

		/**
		 * @brief Configures how the Texture should wrap
		 * 
		 * Controls how the GPU will behave when sampling a Texture outside of the
		 * normal texture area ((0,0) to (1,1))
		 * 
		 * @param s Wrapping behaviour in `s` direction ("horizontal")
		 * @param t Wrapping behaviour in `t` direction ("vertical")
		 * @param r Wrapping behaviour in `r` direction ("depth")
		 */
		void SetWrap(TextureWrap s, TextureWrap t = TextureWrap::Repeat, TextureWrap r = TextureWrap::Repeat);

		/**
		 * @brief Sets the textures border color
		 * 
		 * Only effects textures with wrapping mode TextureWrap::ClampToBorder
		 * 
		 * @param r Red component
		 * @param g Green component
		 * @param b Blue component 
		 * @param a Alpha component
		 */
		void SetBorderColor(float r, float g, float b, float a);

	protected:
		TargetTexture target;
		unsigned int id;
	};


	/**
	 * @brief A 2D Texture object
	 */
	class Texture2D : public Texture
	{
	public:
		/**
		 * @brief Construct a new 2D Texture from an Image
		 * 
		 * @param image 		Image to fetch meta- and pixeldata from
		 * @param texFormat 	Format of the texture
		 */
		Texture2D(const Image& image, TextureFormat texFormat = TextureFormat::RGB);
	};

	/**
	 * @brief A 1D Texture object
	 */
	class Texture1D : public Texture
	{
	public:
		/**
		 * @brief Construct a new 1D Texture from raw data
		 * 
		 * @param width 		Width of the texture
		 * @param data 			Array with pixel color data
		 * @param pixFormat 	Format of the pixel data
		 * @param pixType 		Datatype of each pixel
		 * @param texFormat 	Format of the texture
		 */
		Texture1D(unsigned int width, const void* data, PixelFormat pixFormat = PixelFormat::RGB, PixelType pixType = PixelType::UByte, TextureFormat texFormat = TextureFormat::RGB);
		
		/**
		 * @brief Construct a new 1D Texture from an Image
		 * 
		 * The image doesn't have to have a height of 1 pixel. The texture
		 * will only use the first row of pixels in the Image
		 * 
		 * @param image 	Image to fetch meta- and pixeldata from.
		 * @param texFormat Format of the texture
		 */
		Texture1D(const Image& image, TextureFormat texFormat = TextureFormat::RGB);
	};
}