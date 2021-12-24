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
		Texture(const Image& image, TextureFormat texFormat = TextureFormat::RGB);
		~Texture();

		void Bind();
		void Unbind();

		// TODO: Remove again later
		inline unsigned int GetID() const { return id; }

	private:
		unsigned int id;
	};

	typedef ObjectManager<Texture> TextureManager;
}