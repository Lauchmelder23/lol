#pragma once

#include <lol/util/NonCopyable.hpp>
#include <lol/util/ObjectManager.hpp>

namespace lol
{
	class UniqueTexture;
	typedef std::shared_ptr<UniqueTexture> Texture;

	class UniqueTexture : public NonCopyable
	{
	public:
		UniqueTexture();

		inline static Texture Share()
		{
			return std::make_shared<UniqueTexture>();
		}

	private:
		unsigned int textureID;
	};

	typedef ObjectManager<Texture> TextureManager;
}