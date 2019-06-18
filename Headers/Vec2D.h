#include <SFML/Graphics.hpp>

#pragma once
class Vec2D : public sf::Vector2f
{
public:
	Vec2D(float x = 0, float y = 0);

	Vec2D operator = (float x); // implicit operator in cpp

	Vec2D operator = (sf::Vector2f v);

	~Vec2D();
};

