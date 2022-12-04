#pragma once
#include <memory>

namespace ui
{

class Window;

class RectButton
{
	std::weak_ptr<Window> m_parentWindow;
	SDL_Color m_fillColor;
	SDL_Rect m_area;
public:
	RectButton(std::weak_ptr<Window> parentWindow);
	//void setPosition(Point newPosition) override;
	//void setDimensions(Dimensions newDimensions) override;
	void draw();
	//void processHit() override;
};

}
