#include <lol/Texture.hpp>

#include <glad/glad.h>

#include <lol/Image.hpp>

namespace lol
{
	Texture::Texture(TargetTexture target) :
		id(0), target(target)
	{
		glGenTextures(1, &id);
		glBindTexture(NATIVE(target), id);

		glTexParameteri(NATIVE(target), GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(NATIVE(target), GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &id);
	}

	void Texture::SetWrap(TextureWrap s, TextureWrap t, TextureWrap r)
	{
		glBindTexture(NATIVE(target), id);
		glTexParameteri(NATIVE(target), GL_TEXTURE_WRAP_S, NATIVE(s));
		glTexParameteri(NATIVE(target), GL_TEXTURE_WRAP_T, NATIVE(t));
		glTexParameteri(NATIVE(target), GL_TEXTURE_WRAP_R, NATIVE(r));
	}

	void Texture::SetBorderColor(float r, float g, float b, float a)
	{
		glBindTexture(NATIVE(target), id);

		glm::vec4 color(r, g, b, a);
		glTexParameterfv(NATIVE(target), GL_TEXTURE_BORDER_COLOR, &color[0]);
	}

	void Texture::Bind()
	{
		glBindTexture(NATIVE(target), id);
	}

	void Texture::Unbind()
	{
		glBindTexture(NATIVE(target), 0);
	}


	Texture2D::Texture2D(const Image& image, TextureFormat texFormat) :
		Texture(TargetTexture::Texture2D)
	{
		glm::uvec2 imageSize = image.GetDimensions();
		glTexImage2D(NATIVE(target), 0, NATIVE(texFormat), imageSize.x, imageSize.y, 0, NATIVE(image.GetPixelFormat()), NATIVE(image.GetPixelType()), image.GetPixels());
		glGenerateMipmap(NATIVE(target));
	}


	Texture1D::Texture1D(unsigned int width, const void* data, PixelFormat pixFormat, PixelType pixType, TextureFormat texFormat) :
		Texture(TargetTexture::Texture1D)
	{
		glTexImage1D(NATIVE(target), 0, NATIVE(texFormat), width, 0, NATIVE(pixFormat), NATIVE(pixType), data);
		glGenerateMipmap(NATIVE(target));
	}

	Texture1D::Texture1D(const Image& image, TextureFormat texFormat) :
		Texture(TargetTexture::Texture1D)
	{
		glTexImage1D(NATIVE(target), 0, NATIVE(texFormat), image.GetDimensions().x, 0, NATIVE(image.GetPixelFormat()), NATIVE(image.GetPixelType()), image.GetPixels());
		glGenerateMipmap(NATIVE(target));
	}
}