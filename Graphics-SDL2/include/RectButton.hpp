#pragma once
#include <memory>
#include <Button.hpp>
#include <ClickableRectArea.hpp>

namespace ui::sdl2
{

class Window;

class RectButton : public Button, public ClickableRectArea
{
	std::weak_ptr<Window> m_parentWindow;
public:
	RectButton(std::weak_ptr<Window> parentWindow);
	void setPosition(Point newPosition) override;
	void setDimensions(Dimensions newDimensions) override;
	void draw() override;
	void processHit() override;
};

}
