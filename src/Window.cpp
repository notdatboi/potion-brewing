#include <Window.hpp>
#include <GraphicsUtils.hpp>
#include <RectButton.hpp>

namespace ui::sdl2
{

Uint32 Window::windowFlagsToSDLFlags(Flag flags)
{
	Uint32 result = 0;
	if (utils::enum_cast(flags & Flag::Fullscreen))
		result &= SDL_WINDOW_FULLSCREEN;
	if (utils::enum_cast(flags & Flag::Hidden))
		result &= SDL_WINDOW_HIDDEN;
	if (utils::enum_cast(flags & Flag::Borderless))
		result &= SDL_WINDOW_BORDERLESS;
	if (utils::enum_cast(flags & Flag::Resizable))
		result &= SDL_WINDOW_RESIZABLE;
	if (utils::enum_cast(flags & Flag::Minimized))
		result &= SDL_WINDOW_MINIMIZED;
	if (utils::enum_cast(flags & Flag::Maximized))
		result &= SDL_WINDOW_MAXIMIZED;
	return result;
}

Window::Window()
	: m_window(nullptr)
	, m_renderer(nullptr)
{
}

Window::~Window()
{
	if (m_window)
		SDL_DestroyWindow(m_window);
	if (m_renderer)
		SDL_DestroyRenderer(m_renderer);
}

bool Window::init(compat::cstring_view title, const Rect& windowRect, Flag flags)
{
	m_window = SDL_CreateWindow(title.c_str(), windowRect.x, windowRect.y, static_cast<int>(windowRect.w), static_cast<int>(windowRect.h), windowFlagsToSDLFlags(flags));
	if (!m_window)
		return false;
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (!m_renderer)
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_SOFTWARE);
	return m_renderer;
}

std::shared_ptr<ui::Button> Window::createRectButton()
{
	auto button = std::make_shared<RectButton>(weak_from_this());
	m_drawables.push_back(button);
	return std::move(button);
}

void Window::clear()
{
	LogIfError(SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, SDL_ALPHA_OPAQUE));
	LogIfError(SDL_RenderClear(m_renderer));
}

void Window::draw()
{
	for (const auto& drawable : m_drawables)
	{
		assert(drawable && "Drawables must not be empty");
		drawable->draw();
	}
}

void Window::present()
{
	SDL_RenderPresent(m_renderer);
}

SDL_Window* Window::getWindow() const
{
	return m_window;
}

SDL_Renderer* Window::getRenderer() const
{
	return m_renderer;
}

}
