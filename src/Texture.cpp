#include <lol/Texture.hpp>

#include <glad/glad.h>

#include <lol/Image.hpp>

namespace lol
{
	Texture::Texture(const Image& image, TextureFormat texFormat) :
		id(0)
	{
		glGenTextures(1, &id);
		glBindTexture(GL_TEXTURE_2D, id);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glm::uvec2 imageSize = image.GetDimensions();
		glTexImage2D(GL_TEXTURE_2D, 0, NATIVE(texFormat), imageSize.x, imageSize.y, 0, NATIVE(image.GetPixelFormat()), NATIVE(image.GetPixelType()), image.GetPixels());
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, id);
	}

	void Texture::Unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}