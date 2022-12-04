#include <GraphicsUtils.hpp>
#include <LogDefines.hpp>
#include <SDL3/SDL_error.h>

namespace ui::sdl2
{

void LogIfError(int executionResult)
{
	if (executionResult != 0)
	{
		const char* error = SDL_GetError();
		if (error)
		{
			LOG << "SDL2 error occurred: " << error;
			SDL_ClearError();
		}
	}
}

}
