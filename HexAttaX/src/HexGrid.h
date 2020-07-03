#pragma once

#include <vector>
#include <SFML/Graphics.hpp>


namespace HexGrid
{
	void Init();
	const std::vector<sf::CircleShape*> GetHexagons();
}