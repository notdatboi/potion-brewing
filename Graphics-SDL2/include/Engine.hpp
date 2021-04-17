#pragma once
#include <CommonEngine.hpp>

namespace ui::sdl2
{

class Engine : public ui::Engine
{
	void pumpEvents();
public:
	bool initialize() override;
	void deinitialize() override;
	void pollAndProcessEvent() override;
	void pollAndProcessEvents() override;
	std::shared_ptr<ui::Window> createWindow() override;
};

}
