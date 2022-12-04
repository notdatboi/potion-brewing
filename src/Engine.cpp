#include <Engine.hpp>
#include <LogDefines.hpp>
#include <Window.hpp>

// telling SDL that we won't use it's SDL_main()
#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>

namespace ui
{

bool Engine::initialize()
{
	SDL_SetMainReady();
	const auto result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if (result != 0)
	{
		LOG << "Failed to initialize SDL3, error code: " << result << "; error text: " << SDL_GetError();
		return false;
	}
	m_rootEventHander = std::make_unique<EventHandler>();
	m_valid = true;
	return m_valid;
}

void Engine::deinitialize()
{
	if (m_valid)
	{
		m_valid = false;
		SDL_Quit();
	}
}

bool Engine::isValid() const
{
	return m_valid;
}

void Engine::pollAndProcessEvent()
{
	SDL_Event evt;
	SDL_PollEvent(&evt);
	m_rootEventHander->notify(evt);
}

std::shared_ptr<ui::Window> Engine::createWindow()
{
	std::shared_ptr<ui::Window> window = std::make_shared<Window>();
	m_rootEventHander->addChildHandler(window);
	return window;
}

}
