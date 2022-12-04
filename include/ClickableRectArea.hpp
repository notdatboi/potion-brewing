#pragma once
#include <ClickableArea.hpp>
#include <CommonStructures.hpp>
#include <SDL3/SDL_rect.h>

namespace ui::sdl2
{

class ClickableRectArea : public ClickableArea
{
public:
	ClickableRectArea();
	void setArea(const Rect& area);
	bool isHit(Point p) override;

protected:
	SDL_Rect m_area;
};

}
