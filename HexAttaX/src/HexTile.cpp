#include "HexTile.h"

#include "Colours.h"
#include "Constants.h"
#include "FontUtils.h"
#include "HexUtils.h"
#include "PlayerManager.h"
#include "Window.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_level(0),
	m_player(2),
	m_loc(loc),
	m_hexagon(Constants::HEX_RAD, 6)
{
	sf::Vector2f screenPos = HexUtils::HexToPixel(loc);
	m_hexagon.setPosition(screenPos);
	m_hexagon.setFillColor(Colours::tileBackground);
	m_hexagon.setOutlineThickness(1);
	m_hexagon.setOutlineColor(Colours::tileOutline);
}

void HexTile::Draw() const
{
	// draw the hexagon
	Window::window.draw(m_hexagon);

	if (IsSelected())
	{
		// draw the level number on the hexagon
		sf::Font font;
		if (FontUtils::Load(font, "gamer_font.ttf"))
		{
			sf::Text text;
			text.setFont(font);
			text.setCharacterSize(Constants::FONT_SIZE_TILE);

			text.setString(std::to_string(m_level));
			text.setFillColor(sf::Color::White);
			sf::Vector2f screenPos = HexUtils::HexToPixel(m_loc);
			sf::FloatRect textRect = text.getLocalBounds();
			screenPos += sf::Vector2f(Constants::HEX_RAD - textRect.width / 2.f, 
				Constants::HEX_RAD + Constants::FONT_OFFSET_Y_TILE - textRect.height / 2.f);
			text.setPosition(screenPos);

			Window::window.draw(text);
		}
	}
}

// returns true if selected
bool HexTile::Clicked()
{
	bool selected = false;
	if (!IsSelected())
	{
		// not selected, this now belongs to the active player
		SetPlayer(PlayerManager::GetActivePlayer());
		++m_level;
		PlayerManager::AlterPoints(m_player, 1);
		selected = true;
	}
	else if (PlayerManager::GetActivePlayer() == m_player &&
		m_level < Constants::MAX_LEVEL)
	{
		// already selected by the active player
		// level up this tile
		++m_level;
		PlayerManager::AlterPoints(m_player, 1);
		selected = true;
	}
	return selected;
}

void HexTile::Hover()
{
	if (!IsSelected())
	{
		if (PlayerManager::GetActivePlayer() == 0)
			m_hexagon.setFillColor(Colours::tileHoverP1);
		else
			m_hexagon.setFillColor(Colours::tileHoverP2);
	}
}

void HexTile::Unhover()
{
	if (!IsSelected())
	{
		m_hexagon.setFillColor(Colours::tileBackground);
	}
}

bool HexTile::Propogate(const uint8_t level)
{
	if (level > 0 && 
		m_level == level)
	{
		if (m_player != PlayerManager::GetActivePlayer())
		{
			// change the points
			PlayerManager::AlterPoints(PlayerManager::GetInactivePlayer(), -level);
			PlayerManager::AlterPoints(PlayerManager::GetActivePlayer(), level);
			// give ownership to the current player
			SetPlayer(PlayerManager::GetActivePlayer());
		}
		return true;
	}
	else
	{
		return false;
	}
}

void HexTile::SetPlayer(const uint8_t player)
{
	m_player = PlayerManager::GetActivePlayer();
	if (m_player == 0)
		m_hexagon.setFillColor(Colours::tileBackgroundP1);
	else
		m_hexagon.setFillColor(Colours::tileBackgroundP2);
}