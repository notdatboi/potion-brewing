#pragma once
#include <cstdint>
#include <cstring_view.hpp>
#include <functional>
#include <CommonKeyboard.hpp>
#include <Utils.hpp>

namespace ui
{

static constexpr size_t MAX_INDIVIDUAL_EVENT_NUMBER = 100;

class BasicEventListener
{
public:
	virtual size_t getEventId() const = 0;
	virtual ~BasicEventListener() = default;
};

template<class T>
class EventListener : public BasicEventListener
{
public:
	using Handler = typename T::Handler;
	using Event = typename T::Event;

	EventListener(Event event, Handler handler) : m_event(event), m_handler(std::move(handler)) {}
	size_t getEventId() const override { return static_cast<size_t>(m_event); }
	void notify(const T& eventData) { m_handler(eventData); }

private:
	Event m_event;
	Handler m_handler;
};

struct CommonEventData
{
	uint32_t timestamp = 0;
};

struct WindowBoundEventData : CommonEventData
{
	uint32_t windowId = 0;
};

struct MouseBoundEventData : WindowBoundEventData
{
	enum class Button
	{
		None = 0,
		Left = 1 << 0,
		Middle = 1 << 1,
		Right = 1 << 2,
		X1 = 1 << 3,
		X2 = 1 << 4
	};

	int32_t x = 0; // shift or position
	int32_t y = 0; // shift or position
	bool touchPad = false; // replacement for SDL's `which`
};
DEF_ENUM_OPERATORS(MouseBoundEventData::Button)

struct WindowEventData : WindowBoundEventData
{
	using Handler = std::function<void(const WindowEventData&)>;

	enum class Event
	{
		Shown = MAX_INDIVIDUAL_EVENT_NUMBER * 0,
		Hidden,
		Exposed,
		Moved,
		Resized,
		SizeChanged,
		Minimized,
		Maximized,
		Restored,
		GainedMouseFocus,
		LostMouseFocus,
		GainedKeyboardFocus,
		LostKeyboardFocus,
		Closed,
		Invalid
	};

	uint32_t x = 0; // new width or new x-coordinate
	uint32_t y = 0; // new height or new y-coordinate
};

struct KeyboardEventData : WindowBoundEventData
{
	using Handler = std::function<void(const KeyboardEventData&)>;

	enum class KeyModifier : unsigned int
	{
		None = 0,
		LShift = 1 << 0,
		RShift = 1 << 1,
		LCtrl = 1 << 2,
		RCtrl = 1 << 3,
		LAlt = 1 << 4,
		RAlt = 1 << 5,
		AnyShift = LShift | RShift,
		AnyCtrl = LCtrl | RCtrl,
		AnyAlt = LAlt | RAlt
		// enough for now, will probably add more later
	};

	enum class Event
	{
		KeyDown = MAX_INDIVIDUAL_EVENT_NUMBER * 1,
		KeyUp,
		Invalid
	};

	enum class KeyState
	{
		Pressed,
		Released,
		Invalid
	} keyState = KeyState::Invalid;

	Key scanCode = Key::Invalid;
	Key keyCode = Key::Invalid;

	uint32_t keyModifierMask = static_cast<uint32_t>(KeyModifier::None);
	uint32_t repeatCount = 0;
};
DEF_ENUM_OPERATORS(KeyboardEventData::KeyModifier)

// todo: add test_editing, text_input, joy_axis, joy_ball, joy_hat, joy_button, joy_device,
// controller_axis, controller_button, controller_device, audio_device, touch_finger events if needed

struct MouseMotionEventData : MouseBoundEventData
{
	using Handler = std::function<void(const MouseMotionEventData&)>;

	enum class Event
	{
		Motion = MAX_INDIVIDUAL_EVENT_NUMBER * 2,
		Invalid
	};

	uint32_t pressedButtonMask = static_cast<uint32_t>(Button::None);
	int32_t xRel = 0; // relative x-axis motion
	int32_t yRel = 0; // relative y-axis motion
};

struct MouseButtonEventData : MouseBoundEventData
{
	using Handler = std::function<void(const MouseButtonEventData&)>;

	bool doubleClick = false;

	enum class Event
	{
		ButtonDown = MAX_INDIVIDUAL_EVENT_NUMBER * 3,
		ButtonUp,
		Invalid
	};

	enum class State
	{
		Pressed,
		Released,
		Invalid
	} state = State::Invalid;

	Button button = Button::None;
};

struct MouseWheelEventData : MouseBoundEventData
{
	using Handler = std::function<void(const MouseWheelEventData&)>;

	enum class Event
	{
		WheelMotion = MAX_INDIVIDUAL_EVENT_NUMBER * 4,
		Invalid
	};

	enum class Direction
	{
		Normal,
		Flipped,
		Invalid
	} direction = Direction::Invalid;
};

struct EngineEventData : CommonEventData
{
	using Handler = std::function<void(const EngineEventData&)>;

	enum class Event
	{
		Quit = MAX_INDIVIDUAL_EVENT_NUMBER * 5,
		Invalid
	};
};

struct DropEventData : WindowBoundEventData
{
	using Handler = std::function<void(const DropEventData&)>;

	enum class Event
	{
		DropFile = MAX_INDIVIDUAL_EVENT_NUMBER * 6,
		DropText,
		DropBegin,
		DropComplete,
		Invalid
	};

	compat::cstring_view file;
};

}
