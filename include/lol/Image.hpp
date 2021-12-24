#pragma once

#include <string>

#include <glm/glm.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	
	class Image
	{
	public:
		Image();
		Image(unsigned int width, unsigned int height, PixelFormat pixelFormat = PixelFormat::RGBA, PixelType pixelType = PixelType::UByte);
		Image(const std::string& filepath);
		~Image();

		Image(const Image& other);
		Image& operator=(const Image& other);

		inline const glm::uvec2& GetDimensions() const { return size; }
		inline void* GetPixels() const { return pixels; }

		inline PixelFormat GetPixelFormat() const { return format; }
		inline PixelType GetPixelType() const { return type; }

	private:
		glm::uvec2 size;
		uint8_t* pixels;

		PixelFormat format;
		PixelType type;
	};

}