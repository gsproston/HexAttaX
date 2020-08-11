#pragma once

#include <SFML/Graphics.hpp>


class HexTile
{
public:
	// constructor
	HexTile(const sf::Vector2i& loc);

	// draw methods
	void Draw() const;

	// mouse methods
	bool Clicked();
	void Hover();
	void Unhover();

	// get methods
	uint8_t GetLevel() const { return m_level; };

	// util methods
	bool Propogate(const uint8_t level);

private:
	bool IsSelected() const { return m_player <= 1; };

	void SetPlayer(const uint8_t player);

	uint8_t m_level;
	uint8_t m_player;
	sf::Vector2i m_loc;
	sf::CircleShape m_hexagon;
};