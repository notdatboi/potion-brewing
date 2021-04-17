#pragma once
#include <CommonEventHandler.hpp>
#include <cstring_view.hpp>
#include <Utils.hpp>
#include <CommonButton.hpp>

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

	virtual bool init(compat::cstring_view title, const Rect& windowRect, Flag flags = Flag::None) = 0;
	virtual std::shared_ptr<Button> createRectButton() = 0;
	virtual void clear() = 0;
	virtual void draw() = 0;
	virtual void present() = 0;
	virtual ~Window() = default;
};
DEF_ENUM_OPERATORS(Window::Flag)

}
