#pragma once

namespace ui::sdl2
{

class Drawable
{
public:
	virtual ~Drawable() = default;
	virtual void draw() = 0;
};

}
