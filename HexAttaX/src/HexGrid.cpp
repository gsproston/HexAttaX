#include "HexGrid.h"

#include <unordered_map>

#include "Constants.h"
#include "HashFunctions.h"
#include "HexTile.h"


namespace HexGrid
{
	// anon namespace for encapsulation
	namespace
	{
		std::unordered_map<sf::Vector2i, HexTile> InitGrid()
		{
			const int radius = 2;
			std::unordered_map<sf::Vector2i, HexTile> umap;
			for (int q = -radius; q <= radius; q++) {
				int r1 = std::max(-radius, -q - radius);
				int r2 = std::min(radius, -q + radius);
				for (int r = r1; r <= r2; r++) {
					umap.insert({ sf::Vector2i(q, r), HexTile() });
				}
			}
			return umap;
		}

		// private variables
		std::unordered_map<sf::Vector2i, HexTile> umapTiles = InitGrid();
	}

	std::vector<std::unique_ptr<sf::CircleShape>> GetHexagons()
	{
		std::vector<std::unique_ptr<sf::CircleShape>> hexagons;
		for (auto tile : umapTiles)
		{
			std::unique_ptr<sf::CircleShape> hexagon(new sf::CircleShape(Constants::HEX_RAD, 6));
			float x = Constants::HEX_RAD * (sqrt(3) * tile.first.x + sqrt(3) / 2 * tile.first.y) + tile.first.x;
			float y = Constants::HEX_RAD * (							 3.f / 2 * tile.first.y) + tile.first.y;
			hexagon->setPosition(x, y);
			hexagons.push_back(std::move(hexagon));
		}
		return hexagons;
	}
}