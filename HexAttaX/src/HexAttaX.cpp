#include <SFML/Graphics.hpp>
#include <vector>

#include "HexGrid.h"


int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "HexAttaX", sf::Style::Default, settings);

	window.setFramerateLimit(60);

	HexGrid::Init();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
					window.close();
			}
		}

		window.clear();
		const std::vector<sf::CircleShape*> vHexagons = HexGrid::GetHexagons();
		for (uint32_t i = 0; i < vHexagons.size(); ++i)
		{
			window.draw(*vHexagons[i]);
		}
		window.display();
	}

	return 0;
}