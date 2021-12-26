#pragma once

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>
#include <lol/util/Enums.hpp>

namespace lol
{
	class Image;

	class Texture : public NonCopyable
	{
	public:
		Texture(TargetTexture target);
		~Texture();

		void Bind();
		void Unbind();

		void SetWrap(TextureWrap s, TextureWrap t, TextureWrap r = TextureWrap::Repeat);
		void SetBorderColor(float r, float g, float b, float a);

		// TODO: Remove again later
		inline unsigned int GetID() const { return id; }

	protected:
		TargetTexture target;
		unsigned int id;
	};

	typedef ObjectManager<Texture> TextureManager;


	class Texture2D : public Texture
	{
	public:
		Texture2D(const Image& image, TextureFormat texFormat = TextureFormat::RGB);
	};

	class Texture1D : public Texture
	{
	public:
		Texture1D(unsigned int width, const void* data, PixelFormat pixFormat = PixelFormat::RGB, PixelType pixType = PixelType::UByte, TextureFormat texFormat = TextureFormat::RGB);
		Texture1D(const Image& image, TextureFormat texFormat = TextureFormat::RGB);
	};
}