#pragma once
#include <map>
#include <string>
#include <Engine.hpp>

namespace ui
{

class SDL2Engine : public Engine
{
public:
	bool initialize() override;
	void deinitialize() override;
	std::shared_ptr<Window> createWindow() override;
};

}
