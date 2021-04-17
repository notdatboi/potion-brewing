#pragma once
#include <CommonEngine.hpp>

namespace ui::sdl2
{

class Engine : public ui::Engine
{
public:
	bool initialize() override;
	void deinitialize() override;
	void pollAndProcessEvent() override;
	std::shared_ptr<ui::Window> createWindow() override;
};

}
