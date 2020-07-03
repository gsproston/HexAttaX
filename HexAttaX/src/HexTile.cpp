#include "HexTile.h"

#include "Constants.h"
#include "Window.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_hexagon(Constants::HEX_RAD, 6)
{
	float x = Constants::HEX_RAD * (sqrt(3) * loc.x + sqrt(3) / 2 * loc.y) + loc.x;
	float y = Constants::HEX_RAD * (3.f / 2 * loc.y) + loc.y;
	m_hexagon.setPosition(
		x + Constants::WINDOW_WIDTH / 2 - Constants::HEX_RAD,
		y + Constants::WINDOW_HEIGHT / 2 - Constants::HEX_RAD);
	m_hexagon.setFillColor(sf::Color(125, 175, 255));
}

void HexTile::Draw()
{
	Window::window.draw(m_hexagon);
}