#include <Application.hpp>
#include <LogDefines.hpp>
#include <CommonEvents.hpp>
#include <thread>

namespace
{

const compat::cstring_view MAIN_WINDOW_TITLE = "Potion Brewing";

}

namespace pb
{

Application::Application()
	: m_uiEngine(ui::EngineFactory::produceEngine())
	, m_running(false)
{
}

Application::~Application()
{
	try
	{
		m_uiEngine->deinitialize();
	} catch(...) {}
}

bool Application::initEvents()
{
	m_uiEngine->subscribe(std::make_shared<ui::EventListener<ui::EngineEventData>>(ui::EngineEventData::Event::Quit, [this](const ui::EngineEventData&)
	{
		m_running = false;
	}));
	return true;
}

void Application::draw()
{
	assert(m_mainWindow && "Main window should be initialized");
	m_mainWindow->clear();
	m_mainWindow->draw();
}

void Application::present()
{
	assert(m_mainWindow && "Main window should be initialized");
	m_mainWindow->present();
}

void Application::handleEvents()
{
	m_uiEngine->pollAndProcessEvents();
}

bool Application::init()
{
	LOG << "===Init===";
	bool success = m_uiEngine->initialize();
	m_mainWindow = m_uiEngine->createWindow();
	success &= m_mainWindow->init(MAIN_WINDOW_TITLE, { 100, 100, 800, 600 });
	success &= initEvents();
	LOG << "Init result: " << success;
	m_running = success;
	return success;
}

void Application::run()
{
	LOG << "Starting main loop";
	while (m_running)
	{
		handleEvents();
		draw();
		present();
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	LOG << "Main loop exited";
}

}
