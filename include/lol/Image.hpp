#pragma once

#include <string>

#include <glm/glm.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	/**
	 * @brief Stores and loads image data
	 * 
	 * This class is used to store image pixel- and metadata as well as load
	 * image files from disk. It has no OpenGL equivalent
	 */
	class Image
	{
	public:
		/**
		 * @brief Create new "empty" Image
		 * 
		 * An empty image has a width and height of 0, an empty pixel array and a default PixelFormat (RGB) and PixelType (UByte)
		 */
		Image();

		/**
		 * @brief Create a new Image with the given metadata
		 * 
		 * @param width 		Width of the image
		 * @param height 		Height of the image
		 * @param pixelFormat 	Pixel format of the image (i.e. what color channels exist)
		 * @param pixelType 	Pixel type of the image	(i.e. what datatype each component has)
		 */
		Image(unsigned int width, unsigned int height, PixelFormat pixelFormat = PixelFormat::RGB, PixelType pixelType = PixelType::UByte);

		/**
		 * @brief Load an Image from disk.
		 * 
		 * The meta- and pixeldata is acquired from an image file.
		 * 
		 * @param filepath The image to be loaded
		 */
		Image(const std::string& filepath);

		~Image();

		/**
		 * @brief Copy data of another Image
		 * 
		 * @param other The Image to copy from
		 */
		Image(const Image& other);

		/**
		 * @brief Assign this Image data of another Image
		 * 
		 * @param other The Image to assign from
		 * @return The modified Image
		 */
		Image& operator=(const Image& other);


		/**
		 * @brief Get the dimensions of the image
		 * 
		 * @return A glm::vec2 with the width and height of the image
		 */
		inline const glm::uvec2& GetDimensions() const { return size; }

		/**
		 * @brief Get the raw image pixel data
		 * 
		 * @return A pointer to an array of pixels that can be directly modified
		 */
		inline uint8_t* GetPixels() const { return pixels; }

		/**
		 * @brief Get the format of the Image
		 * 
		 * @return Format of the Image (i.e. what color channels it has)
		 */
		inline PixelFormat GetPixelFormat() const { return format; }

		/**
		 * @brief Get the datatype of the pixels in the Image
		 * 
		 * @return Type of the pixels (i.e. what datatype each color component has)
		 */
		inline PixelType GetPixelType() const { return type; }

	private:
		glm::uvec2 size;
		uint8_t* pixels;

		PixelFormat format;
		PixelType type;
	};

}