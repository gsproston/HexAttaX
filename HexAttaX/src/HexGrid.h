#pragma once

#include <SFML/Graphics.hpp>


namespace HexGrid
{
	void Init();
	void Draw();

	void MouseMoved(const sf::Vector2i& mousePos);
}