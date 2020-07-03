#pragma once

#include <SFML/Graphics.hpp>


class HexTile
{
public:
	HexTile(const sf::Vector2i& loc);

	sf::CircleShape& GetHexagon() { return m_hexagon; };

private:
	sf::CircleShape m_hexagon;
};