#pragma once

#include <stdint.h>


namespace PlayerManager
{
	void Draw();

	void DecrementPoints(const uint8_t player);
	void IncrementPoints(const uint8_t player);

	uint8_t GetActivePlayer();
	void NextActivePlayer();
}