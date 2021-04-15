#pragma once
#include <Window.hpp>
#include <SDL_render.h>

namespace ui
{

class SDL2Window : public Window
{
	SDL_Window* m_window;
public:
	SDL2Window();
	~SDL2Window() override;
	static Uint32 windowFlagsToSDLFlags(Flag flags);
	void init(compat::cstring_view title, Rect windowRect, Flag flags) override;
};

}
