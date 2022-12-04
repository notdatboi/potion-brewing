#include <thread>
#include <iostream>
#include <boost/asio.hpp>
#include <SDL3/SDL_stdinc.h>
#include <Engine.hpp>
#include <LogDefines.hpp>

#ifdef _WIN32
#include <windows.h>

int APIENTRY WinMain(HINSTANCE /*instance*/, HINSTANCE /*prevInstance*/, PSTR /*cmdLine*/, int /*showCmd*/)
#else
int main()
#endif
{
	boost::asio::io_context io;
	//boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	//t.wait();
	std::cout << "Hello, world!" << std::endl;
	auto uiEngine = std::make_shared<ui::Engine>();
	if (uiEngine->initialize())
	{
		auto window = uiEngine->createWindow();
		window->init("TEST", {100, 100, 800, 600}, 0);
		window->present();
		window->subscribe(SDL_MOUSEBUTTONDOWN, [](const SDL_Event&)
		{
			std::cout << "Mouse Key Pressed\n";
		});
		window->subscribe(SDL_KEYDOWN, [uiEngine](const SDL_Event&)
		{
			std::cout << "Keyboard Key Pressed\n";
			uiEngine->deinitialize();
		});
		while (uiEngine->isValid())
		{
			uiEngine->pollAndProcessEvent();
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
		}
		//boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
		//t.wait();
		uiEngine->deinitialize();
	}
	return 0;
}
