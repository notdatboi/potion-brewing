#pragma once
#include <SDL3/SDL_render.h>
#include <memory>
#include <string>
#include <Events.hpp>

namespace ui
{

class Window : public EventHandler, public std::enable_shared_from_this<Window>
{
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	//std::vector<std::shared_ptr<Drawable>> m_drawables;
public:
	Window();
	virtual ~Window();
	bool init(const std::string& title, const SDL_Rect& windowRect, Uint32 flags);
	//std::shared_ptr<ui::Button> createRectButton() override;
	void clear();
	void draw();
	void present();
	SDL_Window* getWindow() const;
	SDL_Renderer* getRenderer() const;
};

}
