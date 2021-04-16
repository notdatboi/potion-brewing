#pragma once
#include <CommonWindow.hpp>
#include <SDL_render.h>

namespace ui::sdl2
{

class Window : public ui::Window
{
	SDL_Window* m_window;
public:
	Window();
	~Window() override;
	static Uint32 windowFlagsToSDLFlags(Flag flags);
	void init(compat::cstring_view title, Rect windowRect, Flag flags) override;
};

}
