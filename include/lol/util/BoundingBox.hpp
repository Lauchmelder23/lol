#pragma once

namespace lol
{

	/**
	 * @brief Defines a rectangle via a point and its dimensions
	 * 
	 */
	struct Rect
	{
		float x, y;	
		float w, h;
	};

	/**
	 * @brief Defines a 3D area in space
	 * 
	 */
	struct BoundingBox
	{
		float x, y, z;
		float w, h, d;
	};

	typedef BoundingBox BBox;

}