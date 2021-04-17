#pragma once
#include <CommonEngine.hpp>

namespace pb
{

class Application
{
	std::unique_ptr<ui::Engine> m_uiEngine;
	std::shared_ptr<ui::Window> m_mainWindow;
	bool m_running;

	bool initEvents();
	void draw();
	void present();
	void handleEvents();

public:
	Application();
	~Application();
	bool init();
	void run();
};

}
