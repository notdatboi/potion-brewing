#include <thread>
#include <iostream>
#include <boost/asio.hpp>
#include <SDL3/SDL_stdinc.h>
/*#include <CommonEngine.hpp>
#include <LogDefines.hpp>
*/
#ifdef _WIN32
#include <windows.h>

int APIENTRY WinMain(HINSTANCE /*instance*/, HINSTANCE /*prevInstance*/, PSTR /*cmdLine*/, int /*showCmd*/)
#else
int main()
#endif
{
	boost::asio::io_context io;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	t.wait();
	std::cout << "Hello, world!" << std::endl;
	/*auto uiEngine = ui::EngineFactory::produceEngine();
	if (uiEngine->initialize())
	{
		uiEngine->deinitialize();
	}
	return 0;*/
}
