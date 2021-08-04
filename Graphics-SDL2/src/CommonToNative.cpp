#include <CommonToNative.hpp>

namespace ui::sdl2
{

void NativeToCommon(const SDL_WindowEvent& src, WindowEventData& dst, WindowEventData::Event& dstEvt)
{
	dst.x = src.data1;
	dst.y = src.data2;
	dst.windowId = src.windowID;
	dst.timestamp = src.timestamp;
	switch (src.event)
	{
		case SDL_WINDOWEVENT_SHOWN:
			dstEvt = WindowEventData::Event::Shown;
			break;
		case SDL_WINDOWEVENT_HIDDEN:
			dstEvt = WindowEventData::Event::Hidden;
			break;
		case SDL_WINDOWEVENT_EXPOSED:
			dstEvt = WindowEventData::Event::Exposed;
			break;
		case SDL_WINDOWEVENT_MOVED:
			dstEvt = WindowEventData::Event::Moved;
			break;
		case SDL_WINDOWEVENT_RESIZED:
			dstEvt = WindowEventData::Event::Resized;
			break;
		case SDL_WINDOWEVENT_SIZE_CHANGED:
			dstEvt = WindowEventData::Event::SizeChanged;
			break;
		case SDL_WINDOWEVENT_MINIMIZED:
			dstEvt = WindowEventData::Event::Minimized;
			break;
		case SDL_WINDOWEVENT_MAXIMIZED:
			dstEvt = WindowEventData::Event::Maximized;
			break;
		case SDL_WINDOWEVENT_RESTORED:
			dstEvt = WindowEventData::Event::Restored;
			break;
		case SDL_WINDOWEVENT_ENTER:
			dstEvt = WindowEventData::Event::GainedMouseFocus;
			break;
		case SDL_WINDOWEVENT_LEAVE:
			dstEvt = WindowEventData::Event::LostMouseFocus;
			break;
		case SDL_WINDOWEVENT_FOCUS_GAINED:
			dstEvt = WindowEventData::Event::GainedKeyboardFocus;
			break;
		case SDL_WINDOWEVENT_FOCUS_LOST:
			dstEvt = WindowEventData::Event::LostKeyboardFocus;
			break;
		case SDL_WINDOWEVENT_CLOSE:
			dstEvt = WindowEventData::Event::Closed;
			break;
		default:
			dstEvt = WindowEventData::Event::Invalid;
	}
}

void NativeToCommon(const SDL_KeyboardEvent& src, KeyboardEventData& dst, KeyboardEventData::Event& dstEvt)
{
	dst.timestamp = src.timestamp;
	dst.windowId = src.windowID;
	dst.repeatCount = src.repeat;
	switch (src.state)
	{
		case SDL_PRESSED:
			dst.keyState = KeyboardEventData::KeyState::Pressed;
			break;
		case SDL_RELEASED:
			dst.keyState = KeyboardEventData::KeyState::Released;
			break;
		default:
			dst.keyState = KeyboardEventData::KeyState::Invalid;
	}
	switch (src.type)
	{
		case SDL_KEYDOWN:
			dstEvt = KeyboardEventData::Event::KeyDown;
			break;
		case SDL_KEYUP:
			dstEvt = KeyboardEventData::Event::KeyUp;
			break;
		default:
			dstEvt = KeyboardEventData::Event::Invalid;
	}
	if (src.keysym.mod & KMOD_LSHIFT)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::LShift;
	if (src.keysym.mod & KMOD_RSHIFT)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::RShift;
	if (src.keysym.mod & KMOD_LCTRL)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::LCtrl;
	if (src.keysym.mod & KMOD_RCTRL)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::RCtrl;
	if (src.keysym.mod & KMOD_LALT)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::LAlt;
	if (src.keysym.mod & KMOD_RALT)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::RAlt;
	if (src.keysym.mod & KMOD_CAPS)
		dst.keyModifierMask = dst.keyModifierMask | KeyboardEventData::KeyModifier::Caps;
	switch (src.keysym.scancode)
	{
		case SDL_SCANCODE_RETURN:
			dst.scanCode = Key::Return;
			break;
		case SDL_SCANCODE_ESCAPE:
			dst.scanCode = Key::Escape;
			break;
		case SDL_SCANCODE_BACKSPACE:
			dst.scanCode = Key::Backspace;
			break;
		case SDL_SCANCODE_TAB:
			dst.scanCode = Key::Tab;
			break;
		case SDL_SCANCODE_SPACE:
			dst.scanCode = Key::Space;
			break;
		case SDL_SCANCODE_COMMA:
			dst.scanCode = Key::Comma;
			break;
		case SDL_SCANCODE_MINUS:
			dst.scanCode = Key::Minus;
			break;
		case SDL_SCANCODE_PERIOD:
			dst.scanCode = Key::Period;
			break;
		case SDL_SCANCODE_SLASH:
			dst.scanCode = Key::Slash;
			break;
		case SDL_SCANCODE_0:
			dst.scanCode = Key::Zero;
			break;
		case SDL_SCANCODE_1:
			dst.scanCode = Key::One;
			break;
		case SDL_SCANCODE_2:
			dst.scanCode = Key::Two;
			break;
		case SDL_SCANCODE_3:
			dst.scanCode = Key::Three;
			break;
		case SDL_SCANCODE_4:
			dst.scanCode = Key::Four;
			break;
		case SDL_SCANCODE_5:
			dst.scanCode = Key::Five;
			break;
		case SDL_SCANCODE_6:
			dst.scanCode = Key::Six;
			break;
		case SDL_SCANCODE_7:
			dst.scanCode = Key::Seven;
			break;
		case SDL_SCANCODE_8:
			dst.scanCode = Key::Eight;
			break;
		case SDL_SCANCODE_9:
			dst.scanCode = Key::Nine;
			break;
		case SDL_SCANCODE_SEMICOLON:
			dst.scanCode = Key::Semicolon;
			break;
		case SDL_SCANCODE_EQUALS:
			dst.scanCode = Key::Equals;
			break;
		case SDL_SCANCODE_LEFTBRACKET:
			dst.scanCode = Key::LeftBracket;
			break;
		case SDL_SCANCODE_BACKSLASH:
			dst.scanCode = Key::Backslash;
			break;
		case SDL_SCANCODE_RIGHTBRACKET:
			dst.scanCode = Key::RightBracket;
			break;
		case SDL_SCANCODE_A:
			dst.scanCode = Key::A;
			break;
		case SDL_SCANCODE_B:
			dst.scanCode = Key::B;
			break;
		case SDL_SCANCODE_C:
			dst.scanCode = Key::C;
			break;
		case SDL_SCANCODE_D:
			dst.scanCode = Key::D;
			break;
		case SDL_SCANCODE_E:
			dst.scanCode = Key::E;
			break;
		case SDL_SCANCODE_F:
			dst.scanCode = Key::F;
			break;
		case SDL_SCANCODE_G:
			dst.scanCode = Key::G;
			break;
		case SDL_SCANCODE_H:
			dst.scanCode = Key::H;
			break;
		case SDL_SCANCODE_I:
			dst.scanCode = Key::I;
			break;
		case SDL_SCANCODE_J:
			dst.scanCode = Key::J;
			break;
		case SDL_SCANCODE_K:
			dst.scanCode = Key::K;
			break;
		case SDL_SCANCODE_L:
			dst.scanCode = Key::L;
			break;
		case SDL_SCANCODE_M:
			dst.scanCode = Key::M;
			break;
		case SDL_SCANCODE_N:
			dst.scanCode = Key::N;
			break;
		case SDL_SCANCODE_O:
			dst.scanCode = Key::O;
			break;
		case SDL_SCANCODE_P:
			dst.scanCode = Key::P;
			break;
		case SDL_SCANCODE_Q:
			dst.scanCode = Key::Q;
			break;
		case SDL_SCANCODE_R:
			dst.scanCode = Key::R;
			break;
		case SDL_SCANCODE_S:
			dst.scanCode = Key::S;
			break;
		case SDL_SCANCODE_T:
			dst.scanCode = Key::T;
			break;
		case SDL_SCANCODE_U:
			dst.scanCode = Key::U;
			break;
		case SDL_SCANCODE_V:
			dst.scanCode = Key::V;
			break;
		case SDL_SCANCODE_W:
			dst.scanCode = Key::W;
			break;
		case SDL_SCANCODE_X:
			dst.scanCode = Key::X;
			break;
		case SDL_SCANCODE_Y:
			dst.scanCode = Key::Y;
			break;
		case SDL_SCANCODE_Z:
			dst.scanCode = Key::Z;
			break;
		default:
			dst.scanCode = Key::Invalid;
	}
	switch (src.keysym.sym)
	{
		case SDLK_RETURN:
			dst.keyCode = Key::Return;
			break;
		case SDLK_ESCAPE:
			dst.keyCode = Key::Escape;
			break;
		case SDLK_BACKSPACE:
			dst.keyCode = Key::Backspace;
			break;
		case SDLK_TAB:
			dst.keyCode = Key::Tab;
			break;
		case SDLK_SPACE:
			dst.keyCode = Key::Space;
			break;
		case SDLK_EXCLAIM:
			dst.keyCode = Key::Exclaim;
			break;
		case SDLK_QUOTEDBL:
			dst.keyCode = Key::QuoteDouble;
			break;
		case SDLK_HASH:
			dst.keyCode = Key::Hash;
			break;
		case SDLK_PERCENT:
			dst.keyCode = Key::Percent;
			break;
		case SDLK_DOLLAR:
			dst.keyCode = Key::Dollar;
			break;
		case SDLK_AMPERSAND:
			dst.keyCode = Key::Ampersand;
			break;
		case SDLK_QUOTE:
			dst.keyCode = Key::Quote;
			break;
		case SDLK_LEFTPAREN:
			dst.keyCode = Key::LeftParenthesis;
			break;
		case SDLK_RIGHTPAREN:
			dst.keyCode = Key::RightParenthesis;
			break;
		case SDLK_ASTERISK:
			dst.keyCode = Key::Asterisk;
			break;
		case SDLK_PLUS:
			dst.keyCode = Key::Plus;
			break;
		case SDLK_COMMA:
			dst.keyCode = Key::Comma;
			break;
		case SDLK_MINUS:
			dst.keyCode = Key::Minus;
			break;
		case SDLK_PERIOD:
			dst.keyCode = Key::Period;
			break;
		case SDLK_SLASH:
			dst.keyCode = Key::Slash;
			break;
		case SDLK_0:
			dst.scanCode = Key::Zero;
			break;
		case SDLK_1:
			dst.scanCode = Key::One;
			break;
		case SDLK_2:
			dst.scanCode = Key::Two;
			break;
		case SDLK_3:
			dst.scanCode = Key::Three;
			break;
		case SDLK_4:
			dst.scanCode = Key::Four;
			break;
		case SDLK_5:
			dst.scanCode = Key::Five;
			break;
		case SDLK_6:
			dst.scanCode = Key::Six;
			break;
		case SDLK_7:
			dst.scanCode = Key::Seven;
			break;
		case SDLK_8:
			dst.scanCode = Key::Eight;
			break;
		case SDLK_9:
			dst.scanCode = Key::Nine;
			break;
		case SDLK_COLON:
			dst.keyCode = Key::Colon;
			break;
		case SDLK_SEMICOLON:
			dst.keyCode = Key::Semicolon;
			break;
		case SDLK_LESS:
			dst.keyCode = Key::Less;
			break;
		case SDLK_EQUALS:
			dst.keyCode = Key::Equals;
			break;
		case SDLK_GREATER:
			dst.keyCode = Key::Greater;
			break;
		case SDLK_QUESTION:
			dst.keyCode = Key::Question;
			break;
		case SDLK_AT:
			dst.keyCode = Key::At;
			break;
		case SDLK_LEFTBRACKET:
			dst.keyCode = Key::LeftBracket;
			break;
		case SDLK_BACKSLASH:
			dst.keyCode = Key::Backslash;
			break;
		case SDLK_RIGHTBRACKET:
			dst.keyCode = Key::RightBracket;
			break;
		case SDLK_CARET:
			dst.keyCode = Key::Caret;
			break;
		case SDLK_UNDERSCORE:
			dst.keyCode = Key::Underscore;
			break;
		case SDLK_BACKQUOTE:
			dst.keyCode = Key::BackQuote;
			break;
		case SDLK_a:
			dst.scanCode = Key::A;
			break;
		case SDLK_b:
			dst.scanCode = Key::B;
			break;
		case SDLK_c:
			dst.scanCode = Key::C;
			break;
		case SDLK_d:
			dst.scanCode = Key::D;
			break;
		case SDLK_e:
			dst.scanCode = Key::E;
			break;
		case SDLK_f:
			dst.scanCode = Key::F;
			break;
		case SDLK_g:
			dst.scanCode = Key::G;
			break;
		case SDLK_h:
			dst.scanCode = Key::H;
			break;
		case SDLK_i:
			dst.scanCode = Key::I;
			break;
		case SDLK_j:
			dst.scanCode = Key::J;
			break;
		case SDLK_k:
			dst.scanCode = Key::K;
			break;
		case SDLK_l:
			dst.scanCode = Key::L;
			break;
		case SDLK_m:
			dst.scanCode = Key::M;
			break;
		case SDLK_n:
			dst.scanCode = Key::N;
			break;
		case SDLK_o:
			dst.scanCode = Key::O;
			break;
		case SDLK_p:
			dst.scanCode = Key::P;
			break;
		case SDLK_q:
			dst.scanCode = Key::Q;
			break;
		case SDLK_r:
			dst.scanCode = Key::R;
			break;
		case SDLK_s:
			dst.scanCode = Key::S;
			break;
		case SDLK_t:
			dst.scanCode = Key::T;
			break;
		case SDLK_u:
			dst.scanCode = Key::U;
			break;
		case SDLK_v:
			dst.scanCode = Key::V;
			break;
		case SDLK_w:
			dst.scanCode = Key::W;
			break;
		case SDLK_x:
			dst.scanCode = Key::X;
			break;
		case SDLK_y:
			dst.scanCode = Key::Y;
			break;
		case SDLK_z:
			dst.scanCode = Key::Z;
			break;
		default:
			dst.keyCode = Key::Invalid;
	}
}

}
