#pragma once
#include <memory>
#include <map>
#include <EventHandler.hpp>
#include <Window.hpp>

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
	virtual std::shared_ptr<Window> createWindow() = 0;
	virtual ~Engine() = default;
};

}
