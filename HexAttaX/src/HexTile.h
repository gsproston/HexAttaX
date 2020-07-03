#pragma once

#include <SFML/Graphics.hpp>


class HexTile
{
public:
	HexTile(const sf::Vector2i& loc);

	void Draw();

private:
	sf::CircleShape m_hexagon;
};