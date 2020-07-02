#include <SFML/Graphics.hpp>
#include <vector>

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

		std::vector<sf::Vector2i> vPoints =
		{
			sf::Vector2i(0, 0),
			sf::Vector2i(1, 0),
			sf::Vector2i(0, 1),
			sf::Vector2i(1, 1)
		};

		window.clear();
		for (const sf::Vector2i& point : vPoints)
		{
			const float size = 50.f;
			// make hexagon and draw it
			sf::CircleShape hexagon(size, 6);
			float x = size * (sqrt(3) * point.x + sqrt(3) / 2 * point.y) + point.x;
			float y = size * (						  3.f / 2 * point.y) + point.y;
			hexagon.setPosition(x, y);
			window.draw(hexagon);
		}
		window.display();
	}

	return 0;
}