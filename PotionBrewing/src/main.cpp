#include <Application.hpp>

#ifdef _WIN32
#include <windows.h>

int APIENTRY WinMain(HINSTANCE /*instance*/, HINSTANCE /*prevInstance*/, PSTR /*cmdLine*/, int /*showCmd*/)
#else
int main()
#endif
{
	pb::Application app;
	if (app.init())
		app.run();
	return 0;
}
