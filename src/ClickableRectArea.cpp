#include <ClickableRectArea.hpp>
#include <CommonToNative.hpp>

namespace ui::sdl2
{

ClickableRectArea::ClickableRectArea()
	: ClickableArea()
	, m_area{0, 0, 0, 0}
{
}

void ClickableRectArea::setArea(const Rect& area)
{
	m_area = CommonToNative(area);
}

bool ClickableRectArea::isHit(Point p)
{
	return p.x >= m_area.x && p.y >= m_area.y
		&& p.x <= m_area.x + m_area.w && p.y <= m_area.y + m_area.h;
}

}
