#include <lol/Texture.hpp>

#include <glad/glad.h>

namespace lol
{
	UniqueTexture::UniqueTexture() :
		textureID(0)
	{
		glGenTextures(1, &textureID);

		glBindTexture(GL_TEXTURE_2D, textureID);
		// glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_UNSIGNED_BYTE, data);
	}

	UniqueTexture::~UniqueTexture()
	{
		glDeleteTextures(1, &textureID);
	}
}