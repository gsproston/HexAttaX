#include "HexTile.h"

#include "Colours.h"
#include "Constants.h"
#include "HexUtils.h"
#include "Window.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_hexagon(Constants::HEX_RAD, 6)
{
	sf::Vector2f screenPos = HexUtils::HexToPixel(loc);
	m_hexagon.setPosition(screenPos);
	m_hexagon.setFillColor(Colours::tileBackground);
	m_hexagon.setOutlineThickness(1);
	m_hexagon.setOutlineColor(Colours::tileOutline);
}

void HexTile::Draw() const
{
	Window::window.draw(m_hexagon);
}

void HexTile::Hover()
{
	m_hexagon.setFillColor(Colours::tileHover);
}

void HexTile::Unhover()
{
	m_hexagon.setFillColor(Colours::tileBackground);
}