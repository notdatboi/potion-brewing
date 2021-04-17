#pragma once
#include <cstdint>

namespace ui
{

struct RGBA
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
};

struct Point
{
	int32_t x;
	int32_t y;
};

struct Dimensions
{
	uint32_t w;
	uint32_t h;
};

struct Rect
{
	int32_t x;
	int32_t y;
	uint32_t w;
	uint32_t h;
};

}
