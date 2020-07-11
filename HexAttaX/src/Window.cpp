#include "Window.h"

#include "Colours.h"
#include "Constants.h"
#include "HexGrid.h"


namespace Window
{
	sf::RenderWindow window;

	void Init()
	{
		sf::ContextSettings settings;
		settings.antialiasingLevel = 8;
		window.create(sf::VideoMode(
			Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT),
			"HexAttaX", 0x5, settings);
		window.setFramerateLimit(60);
	}

	void Display()
	{
		window.display();
		window.clear(Colours::screenBackground);
	}

	void PollEvent()
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

			if (event.type == sf::Event::MouseMoved)
			{
				const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				HexGrid::MouseMoved(mousePos);
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				const sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				HexGrid::MouseButtonReleased(mousePos);
			}
		}
	}
}