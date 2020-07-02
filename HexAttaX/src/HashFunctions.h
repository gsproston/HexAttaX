#pragma once

#include <SFML/Graphics.hpp>


template<> struct std::hash<sf::Vector2i> {
	std::size_t operator()(sf::Vector2i const& s) const noexcept {
		std::size_t h1 = std::hash<int>{}(s.x);
		std::size_t h2 = std::hash<int>{}(s.y);
		return h1 ^ (h2 << 1);
	}
};