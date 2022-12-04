#include <Button.hpp>

namespace ui::sdl2
{

Button::Button()
	: ui::Button()
	, m_hitHandler([]{}) // so we can safely call it
	, m_fillColor{0, 0, 0, 0}
{
}

void Button::setHitHandler(HitHandler handler)
{
	m_hitHandler = std::move(handler);
}

void Button::setFillColor(const RGBA& color)
{
	m_fillColor = color;
}

}
