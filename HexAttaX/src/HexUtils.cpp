#include "HexUtils.h"

#include "Constants.h"


namespace HexUtils
{
	sf::Vector2i HexRound(const sf::Vector2f& loc)
	{
		float z = -loc.x - loc.y;
		int rx = round(loc.x);
		int ry = round(loc.y);
		int rz = round(z);

		float x_diff = abs(rx - loc.x);
		float y_diff = abs(ry - loc.y);
		float z_diff = abs(rz - z);

		if (x_diff > y_diff && x_diff > z_diff)
			rx = -ry - rz;
		else if (y_diff > z_diff)
			ry = -rx - rz;
		else
			rz = -rx - ry;

		return sf::Vector2i(rx, ry);
	}

	sf::Vector2f HexToPixel(const sf::Vector2i& loc)
	{
		const float x = Constants::HEX_RAD * (sqrt(3) * loc.x + sqrt(3) / 2 * loc.y)
			+ Constants::WINDOW_WIDTH / 2 - Constants::HEX_RAD;
		const float y = Constants::HEX_RAD * (					    3.f / 2 * loc.y)
			+ Constants::WINDOW_HEIGHT / 2 - Constants::HEX_RAD;
		return sf::Vector2f(x, y);
	}

	sf::Vector2i PixelToHex(const sf::Vector2i& screenPos)
	{
		const float x = screenPos.x - Constants::WINDOW_WIDTH / 2;
		const float y = screenPos.y - Constants::WINDOW_HEIGHT / 2;
		const float q = (sqrt(3) / 3 * x - 1. / 3 * y) / Constants::HEX_RAD;
		const float r = (				   2. / 3 * y) / Constants::HEX_RAD;
		return HexRound(sf::Vector2f(q, r));
	}
}