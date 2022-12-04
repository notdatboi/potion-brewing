#pragma once
#include <CommonButton.hpp>
#include <Drawable.hpp>

namespace ui::sdl2
{

class Button : public ui::Button, public Drawable
{
public:
	Button();
	~Button() override = default;
	void setHitHandler(HitHandler handler) override;
	void setFillColor(const RGBA& color) override;

protected:
	HitHandler m_hitHandler;
	RGBA m_fillColor;
};

}
