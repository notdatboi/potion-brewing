#pragma once
#include <memory>
#include <CommonEventHandler.hpp>
#include <CommonWindow.hpp>

namespace ui
{

class Engine;

class EngineFactory
{
public:
	static std::unique_ptr<Engine> produceEngine();
};

class Engine : public EventHandler
{
public:
	virtual bool initialize() = 0;
	virtual void deinitialize() = 0;
	virtual void pollAndProcessEvent() = 0;
	virtual std::shared_ptr<Window> createWindow() = 0;
	virtual ~Engine() = default;
};

}
