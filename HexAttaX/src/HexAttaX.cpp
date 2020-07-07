#include "HexGrid.h"
#include "FontUtils.h"
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
		if (FontUtils::Load(font, "gamer_font.ttf"))
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