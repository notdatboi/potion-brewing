#include <Engine.hpp>
#include <LogDefines.hpp>
#include <Window.hpp>

// telling SDL that we won't use it's SDL_main()
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace ui
{

std::unique_ptr<Engine> EngineFactory::produceEngine()
{
	return std::make_unique<sdl2::Engine>();
}

}

namespace ui::sdl2
{

bool Engine::initialize()
{
	SDL_SetMainReady();
	const auto result = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
	if (result != 0)
	{
		LOG << "Failed to initialize SDL2, error code: " << result << "; error text: " << SDL_GetError();
		return false;
	}
	return true;
}

void Engine::deinitialize()
{
	SDL_Quit();
}

std::shared_ptr<ui::Window> Engine::createWindow()
{
	std::shared_ptr<ui::Window> window = std::make_shared<Window>();
	m_childHandlers.push_back(window);
	return window;
}

}
