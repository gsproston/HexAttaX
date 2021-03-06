#include "PlayerManager.h"

#include <array>
#include <SFML/Graphics.hpp>

#include "Colours.h"
#include "Constants.h"
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
			text.setCharacterSize(Constants::FONT_SIZE);
			text.setOutlineThickness(1);

			text.setString("P1");
			text.setFillColor(Colours::textP1);
			text.setOutlineColor(Colours::textOutlineP1);
			text.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH / 8.f, 
				Constants::WINDOW_HEIGHT / 2.5f + Constants::FONT_OFFSET_Y));
			Window::window.draw(text);

			text.setString(std::to_string(aPlayers[0].m_points));
			text.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH / 8.f,
				Constants::WINDOW_HEIGHT / 2.f + Constants::FONT_OFFSET_Y));
			Window::window.draw(text);

			text.setString("P2");
			text.setFillColor(Colours::textP2);
			text.setOutlineColor(Colours::textOutlineP2);
			text.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH * 6.5f / 8.f, 
				Constants::WINDOW_HEIGHT / 2.5f + Constants::FONT_OFFSET_Y));
			Window::window.draw(text);

			text.setString(std::to_string(aPlayers[1].m_points));
			text.setPosition(sf::Vector2f(Constants::WINDOW_WIDTH * 6.5f / 8.f,
				Constants::WINDOW_HEIGHT / 2.f + Constants::FONT_OFFSET_Y));
			Window::window.draw(text);
		}
	}

	void AlterPoints(const uint8_t player,
		const int8_t diff)
	{
		aPlayers[player].m_points += diff;
	}

	uint8_t GetActivePlayer()
	{
		return activePlayer;
	}

	uint8_t GetInactivePlayer()
	{
		return (activePlayer + 1) % 2;
	}

	void NextActivePlayer()
	{
		activePlayer = (activePlayer + 1) % 2;
	}
}