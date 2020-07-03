#include "HexTile.h"

#include "Constants.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_hexagon(Constants::HEX_RAD, 6)
{
	float x = Constants::HEX_RAD * (sqrt(3) * loc.x + sqrt(3) / 2 * loc.y) + loc.x;
	float y = Constants::HEX_RAD * (3.f / 2 * loc.y) + loc.y;
	m_hexagon.setPosition(x, y);
}