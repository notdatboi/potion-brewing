#pragma once
#include <CommonButton.hpp>

namespace ui::sdl2
{

class Button : public ui::Button
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
