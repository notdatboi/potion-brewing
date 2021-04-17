#include <RectButton.hpp>
#include <Window.hpp>
#include <GraphicsUtils.hpp>

namespace ui::sdl2
{

RectButton::RectButton(std::weak_ptr<Window> parentWindow)
	: Button()
	, ClickableRectArea()
	, m_parentWindow(std::move(parentWindow))
{
}

void RectButton::setPosition(Point newPosition)
{
	m_area.x = newPosition.x;
	m_area.y = newPosition.y;
}

void RectButton::setDimensions(Dimensions newDimensions)
{
	m_area.w = newDimensions.w;
	m_area.h = newDimensions.h;
}

void RectButton::draw()
{
	const auto window = m_parentWindow.lock();
	if (window)
	{
		LogIfError(SDL_SetRenderDrawColor(window->getRenderer(), m_fillColor.r, m_fillColor.g, m_fillColor.b, m_fillColor.a));
		LogIfError(SDL_RenderFillRect(window->getRenderer(), &m_area));
	}
}

void RectButton::processHit()
{
	m_hitHandler();
}

}
