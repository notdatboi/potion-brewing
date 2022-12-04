#pragma once
#include <functional>
#include <CommonStructures.hpp>

namespace ui
{

class Button
{
public:
	using HitHandler = std::function<void()>;

	virtual ~Button() = default;
	virtual void setHitHandler(HitHandler handler) = 0;
	virtual void setFillColor(const RGBA& color) = 0;
	virtual void setPosition(Point newPosition) = 0;
	virtual void setDimensions(Dimensions newDimensions) = 0;
	//virtual void setTexture() = 0;
	//virtual void setBorder() = 0;
	//virtual void setShadow() = 0;
	//virtual void setText() = 0;
};

}
