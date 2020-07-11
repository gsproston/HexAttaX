#include "HexTile.h"

#include "Colours.h"
#include "Constants.h"
#include "HexUtils.h"
#include "PlayerManager.h"
#include "Window.h"


HexTile::HexTile(const sf::Vector2i& loc):
	m_player(2),
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
	Window::window.draw(m_hexagon);
}

void HexTile::Clicked()
{
	if (!IsSelected())
	{
		m_player = PlayerManager::GetActivePlayer();
		if (m_player == 0)
			m_hexagon.setFillColor(Colours::tileBackgroundP1);
		else
			m_hexagon.setFillColor(Colours::tileBackgroundP2);
	}
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