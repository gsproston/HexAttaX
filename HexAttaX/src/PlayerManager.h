#pragma once

#include <stdint.h>


namespace PlayerManager
{
	void Draw();

	void AlterPoints(const uint8_t player,
		const int8_t diff);

	uint8_t GetActivePlayer();
	uint8_t GetInactivePlayer();
	void NextActivePlayer();
}