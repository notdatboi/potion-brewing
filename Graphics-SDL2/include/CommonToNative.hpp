#pragma once
#include <CommonStructures.hpp>
#include <SDL_rect.h>

namespace ui::sdl2
{

inline SDL_Rect CommonToNative(const Rect& r) { return { r.x, r.y, static_cast<int>(r.w), static_cast<int>(r.h)}; }
inline Rect NativeToCommon(const SDL_Rect& r) { return { r.x, r.y, static_cast<uint32_t>(r.w), static_cast<uint32_t>(r.h)}; }

}
