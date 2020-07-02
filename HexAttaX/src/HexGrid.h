#pragma once

#include <vector>
#include <SFML/Graphics.hpp>


namespace HexGrid
{
	std::vector<std::unique_ptr<sf::CircleShape>> GetHexagons();
}