#pragma once
#include <Window.hpp>

namespace ui::sdl2
{

class Engine
{
public:
	Engine() = default;
	bool initialize();
	void deinitialize();
	void pollAndProcessEvent();
	std::shared_ptr<ui::sdl2::Window> createWindow();
	virtual ~Engine() = default;
};

}
