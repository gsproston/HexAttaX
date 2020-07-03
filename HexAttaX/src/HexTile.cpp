#include "HexTile.h"

#include "Colours.h"
#include "Constants.h"
#include "Window.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_hexagon(Constants::HEX_RAD, 6)
{
	float x = Constants::HEX_RAD * (sqrt(3) * loc.x + sqrt(3) / 2 * loc.y);
	float y = Constants::HEX_RAD * (3.f / 2 * loc.y);
	m_hexagon.setPosition(
		x + Constants::WINDOW_WIDTH / 2 - Constants::HEX_RAD,
		y + Constants::WINDOW_HEIGHT / 2 - Constants::HEX_RAD);
	m_hexagon.setFillColor(Colours::tile);
	m_hexagon.setOutlineThickness(1);
	m_hexagon.setOutlineColor(Colours::tileOutline);
}

void HexTile::Draw()
{
	Window::window.draw(m_hexagon);
}