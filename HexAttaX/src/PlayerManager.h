#pragma once

#include <stdint.h>


namespace PlayerManager
{
	void Draw();

	uint8_t GetActivePlayer();
	void NextActivePlayer();
}