#pragma once
#include <CommonWindow.hpp>
#include <Drawable.hpp>
#include <SDL_render.h>

namespace ui::sdl2
{

class Window : public ui::Window, public std::enable_shared_from_this<Window>
{
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	std::vector<std::shared_ptr<Drawable>> m_drawables;
public:
	Window();
	~Window() override;
	static Uint32 windowFlagsToSDLFlags(Flag flags);
	bool init(compat::cstring_view title, const Rect& windowRect, Flag flags) override;
	std::shared_ptr<ui::Button> createRectButton() override;
	void clear() override;
	void draw() override;
	void present() override;
	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;
};

}
