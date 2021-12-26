#include <lol/Image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stbi_image.h>

namespace lol
{
	Image::Image() :
		size(0), pixels(nullptr), format(PixelFormat::RGBA), type(PixelType::UByte)
	{
	}

	Image::Image(unsigned int width, unsigned int height, PixelFormat pixelFormat, PixelType pixelType) :
		size(width, height), format(pixelFormat), type(pixelType)
	{
		pixels = new uint8_t[width * height * SizeOf(pixelType)];
	}

	Image::Image(const std::string& filepath)
	{
		int width, height, channels;
		pixels = stbi_load(filepath.c_str(), &width, &height, &channels, 0);

		size = glm::uvec2(width, height);
		type = PixelType::UByte;
		switch (channels)
		{
		case 1:	format = PixelFormat::R;	break;
		case 2:	format = PixelFormat::RG;	break;
		case 3:	format = PixelFormat::RGB;	break;
		case 4:	format = PixelFormat::RGBA; break;
		default:
			format = PixelFormat::RGB;
			break;
		}
	}

	Image::~Image()
	{
		if(pixels != nullptr)
			stbi_image_free(pixels);
	}

	Image::Image(const Image& other)
	{
		size = other.size;
		format = other.format;
		type = other.type;

		pixels = new uint8_t[size.x * size.y * SizeOf(type)];
		*pixels = *other.pixels;
	}

	Image& Image::operator=(const Image& other)
	{
		size = other.size;
		format = other.format;
		type = other.type;

		pixels = new uint8_t[size.x * size.y * SizeOf(type)];
		*pixels = *other.pixels;

		return *this;
	}
}