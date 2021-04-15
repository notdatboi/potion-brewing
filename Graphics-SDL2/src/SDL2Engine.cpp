#include <SDL2Engine.hpp>
#include <LogDefines.hpp>
#include <SDL2Window.hpp>

// telling SDL that we won't use it's SDL_main()
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace ui
{

std::unique_ptr<Engine> EngineFactory::produceEngine()
{
	return std::make_unique<SDL2Engine>();
}

bool SDL2Engine::initialize()
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

void SDL2Engine::deinitialize()
{
	SDL_Quit();
}

std::shared_ptr<Window> SDL2Engine::createWindow()
{
	std::shared_ptr<Window> window = std::make_shared<SDL2Window>();
	m_childHandlers.push_back(window);
	return window;
}

}
