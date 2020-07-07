#include "HexGrid.h"
#include "PathUtils.h"
#include "Window.h"


int main()
{
	Window::Init();
	HexGrid::Init();

	while (Window::window.isOpen())
	{
		Window::PollEvent();

		HexGrid::Draw();
		sf::Font font;
		std::string fontPath;
		if (PathUtils::GetExePath(fontPath) &&
			font.loadFromFile(fontPath + "gamer_font.ttf"))
		{
			sf::Text text;
			text.setFont(font);
			text.setString("P1");
			text.setCharacterSize(128);
			text.setFillColor(sf::Color::Black);
			Window::window.draw(text);
		}

		Window::Display();
	}

	return 0;
}