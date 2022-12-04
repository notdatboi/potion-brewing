#pragma once
#include <Window.hpp>
#include <Events.hpp>

namespace ui
{

class Engine
{
	std::unique_ptr<EventHandler> m_rootEventHander;
	bool m_valid = false;
public:
	Engine() = default;
	bool initialize();
	void deinitialize();
	bool isValid() const;
	void pollAndProcessEvent();
	std::shared_ptr<ui::Window> createWindow();
	virtual ~Engine() = default;
};

}
