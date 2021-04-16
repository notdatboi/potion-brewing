#include <thread>
#include <CommonEngine.hpp>
#include <LogDefines.hpp>

#ifdef _WIN32
#include <windows.h>

int APIENTRY WinMain(HINSTANCE /*instance*/, HINSTANCE /*prevInstance*/, PSTR /*cmdLine*/, int /*showCmd*/)
#else
int main()
#endif
{
	auto uiEngine = ui::EngineFactory::produceEngine();
	if (uiEngine->initialize())
	{
		uiEngine->deinitialize();
	}
	return 0;
}
