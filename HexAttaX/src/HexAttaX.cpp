#include <SFML/Graphics.hpp>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1280, 720), "HexAttaX", sf::Style::Default, settings);

	window.setFramerateLimit(60);

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

		sf::CircleShape hexagon(50, 6);

		window.clear();
		window.draw(hexagon);
		window.display();
	}

	return 0;
}