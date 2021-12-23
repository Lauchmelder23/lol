#pragma once

#include <lol/util/NonCopyable.hpp>

namespace lol
{
	class Texture2D : public NonCopyable
	{
	public:
		Texture2D();

	private:
		unsigned int textureID;
	};
}