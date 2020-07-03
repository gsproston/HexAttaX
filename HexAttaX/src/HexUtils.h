#pragma once

#include <SFML/Graphics.hpp>


namespace HexUtils
{
	sf::Vector2i HexRound(const sf::Vector2f& loc);
	sf::Vector2f HexToPixel(const sf::Vector2i& loc);
	sf::Vector2i PixelToHex(const sf::Vector2i& screenPos);
}