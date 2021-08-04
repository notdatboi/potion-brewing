#pragma once
#include <CommonStructures.hpp>
#include <CommonEvents.hpp>
#include <SDL_events.h>
#include <SDL_rect.h>

namespace ui::sdl2
{

inline SDL_Rect CommonToNative(const Rect& r) { return { r.x, r.y, static_cast<int>(r.w), static_cast<int>(r.h)}; }
inline Rect NativeToCommon(const SDL_Rect& r) { return { r.x, r.y, static_cast<uint32_t>(r.w), static_cast<uint32_t>(r.h)}; }

void NativeToCommon(const SDL_WindowEvent& src, WindowEventData& dst, WindowEventData::Event& dstEvt);
void NativeToCommon(const SDL_KeyboardEvent& src, KeyboardEventData& dst, KeyboardEventData::Event& dstEvt);
}
