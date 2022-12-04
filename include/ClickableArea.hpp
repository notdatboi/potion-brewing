#pragma once
#include <CommonStructures.hpp>

namespace ui::sdl2
{

class ClickableArea
{
public:
	virtual ~ClickableArea() = default;
	virtual bool isHit(Point p) = 0;
	virtual void processHit() = 0;
};

}
