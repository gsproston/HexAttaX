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
		// private variables
		std::unordered_map<sf::Vector2i, std::unique_ptr<HexTile>> umapTiles;
	}

	void Init()
	{
		umapTiles.clear();
		const int radius = 2;
		for (int q = -radius; q <= radius; q++) {
			int r1 = std::max(-radius, -q - radius);
			int r2 = std::min(radius, -q + radius);
			for (int r = r1; r <= r2; r++) {
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
}