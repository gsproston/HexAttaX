#pragma once

#include <SFML/Graphics.hpp>


namespace Window
{
	extern sf::RenderWindow window;

	void Init();
	void Display();
	void PollEvent();
}