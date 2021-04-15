#pragma once
#include <EventHandler.hpp>
#include <cstring_view.hpp>
#include <Utils.hpp>

namespace ui
{

class Window : public EventHandler
{
public:
	struct Rect
	{
		int32_t x;
		int32_t y;
		size_t w;
		size_t h;
	};

	enum class Flag
	{
		None = 0,
		Fullscreen = 1 << 0,
		Hidden = 1 << 1,
		Borderless = 1 << 2,
		Resizable = 1 << 3,
		Minimized = 1 << 4,
		Maximized = 1 << 5
		// add more if needed
	};

	virtual void init(compat::cstring_view title, Rect windowRect, Flag flags = Flag::None) = 0;
	virtual ~Window() = default;
};
DEF_ENUM_OPERATORS(Window::Flag)

}
