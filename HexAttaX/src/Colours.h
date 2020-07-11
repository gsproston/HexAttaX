#pragma once

#include <SFML/Graphics.hpp>


namespace Colours
{
	// window
	const sf::Color screenBackground(220, 220, 220);

	// tiles
	const sf::Color tileBackground(230, 230, 230);
	const sf::Color tileBackgroundP1(255, 50, 50);
	const sf::Color tileBackgroundP2(50, 50, 255);
	const sf::Color tileHoverP1(220, 180, 180);
	const sf::Color tileHoverP2(180, 180, 220);
	const sf::Color tileOutline(160, 160, 160);

	// text
	const sf::Color textP1(255, 50, 50);
	const sf::Color textP2(50, 50, 255);
	const sf::Color textOutlineP1(150, 0, 0);
	const sf::Color textOutlineP2(0, 0, 150);
}