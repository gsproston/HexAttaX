#include "PlayerManager.h"

#include <array>
#include <SFML/Graphics.hpp>

#include "FontUtils.h"
#include "Player.h"
#include "Window.h"


namespace PlayerManager
{
	namespace
	{
		uint8_t activePlayer = 0;
		std::array<Player, 2> aPlayers;
	}

	void Draw()
	{
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
	}

	uint8_t GetActivePlayer()
	{
		return activePlayer;
	}
}