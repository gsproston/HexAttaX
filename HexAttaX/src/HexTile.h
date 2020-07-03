#pragma once

#include <SFML/Graphics.hpp>


class HexTile
{
public:
	HexTile(const sf::Vector2i& loc);

	void Draw() const;

	void Hover();
	void Unhover();

private:
	sf::CircleShape m_hexagon;
};