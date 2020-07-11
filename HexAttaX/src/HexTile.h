#pragma once

#include <SFML/Graphics.hpp>


class HexTile
{
public:
	HexTile(const sf::Vector2i& loc);

	void Draw() const;

	void Clicked();
	void Hover();
	void Unhover();

private:
	bool IsSelected() const { return m_player <= 1; };

	uint8_t m_level;
	uint8_t m_player;
	sf::Vector2i m_loc;
	sf::CircleShape m_hexagon;
};