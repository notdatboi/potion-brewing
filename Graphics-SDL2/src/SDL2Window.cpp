#include <SDL2Window.hpp>

namespace ui
{

Uint32 SDL2Window::windowFlagsToSDLFlags(Flag flags)
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

SDL2Window::SDL2Window()
	: m_window(nullptr)
{
}

SDL2Window::~SDL2Window()
{
	if (m_window)
		SDL_DestroyWindow(m_window);
}

void SDL2Window::init(compat::cstring_view title, Rect windowRect, Flag flags)
{
	m_window = SDL_CreateWindow(title.c_str(), windowRect.x, windowRect.y, static_cast<int>(windowRect.w), static_cast<int>(windowRect.h), windowFlagsToSDLFlags(flags));
}

}
