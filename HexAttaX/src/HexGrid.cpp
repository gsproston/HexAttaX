#include "HexGrid.h"

#include <array>
#include <unordered_map>

#include "Constants.h"
#include "HashFunctions.h"
#include "HexUtils.h"
#include "HexTile.h"
#include "PlayerManager.h"


namespace HexGrid
{
	// anon namespace for encapsulation
	namespace
	{
		// private variables
		std::unordered_map<sf::Vector2i, std::unique_ptr<HexTile>> umapTiles;
	}

	void Init()
	{
		umapTiles.clear();
		const int radius = 2;
		for (int q = -radius; q <= radius; q++) 
		{
			int r1 = std::max(-radius, -q - radius);
			int r2 = std::min(radius, -q + radius);
			for (int r = r1; r <= r2; r++) 
			{
				const sf::Vector2i loc(q, r);
				umapTiles.insert({ loc, std::unique_ptr<HexTile>(new HexTile(loc)) });
			}
		}
	}

	void Draw()
	{
		for (auto it = umapTiles.begin(); it != umapTiles.end(); ++it)
		{
			(*it).second->Draw();
		}
	}

	void Propogate(const sf::Vector2i& loc,
		const int level)
	{
		// get neighbours
		const std::array<sf::Vector2i, 6> dirs =
		{
			sf::Vector2i(1, 0),
			sf::Vector2i(1, -1),
			sf::Vector2i(0, -1),
			sf::Vector2i(-1, 0),
			sf::Vector2i(-1, 1),
			sf::Vector2i(0, 1),
		};

		for (const sf::Vector2i dir : dirs)
		{
			if (umapTiles.find(loc + dir) != umapTiles.end())
			{
				if (umapTiles.at(loc + dir)->Propogate(level - 1))
				{
					Propogate(loc + dir, level - 1);
				}
			}
		}
	}

	void MouseMoved(const sf::Vector2i& mousePos)
	{
		sf::Vector2i selectedHexTile = HexUtils::PixelToHex(mousePos);
		for (auto it = umapTiles.begin(); it != umapTiles.end(); ++it)
		{
			if ((*it).first == selectedHexTile)
				(*it).second->Hover();
			else
				(*it).second->Unhover();
		}
	}

	void MouseButtonReleased(const sf::Vector2i& mousePos)
	{
		sf::Vector2i selectedHexTile = HexUtils::PixelToHex(mousePos);
		if (umapTiles.find(selectedHexTile) != umapTiles.end())
		{
			if (umapTiles.at(selectedHexTile)->Clicked())
			{
				// propogate selection to neighbouring tiles
				Propogate(selectedHexTile, umapTiles.at(selectedHexTile)->GetLevel());
				// pass control to the next player
				PlayerManager::NextActivePlayer();
			}
		}
	}
}
