#include <SFML/Graphics.hpp>
#include "Vec2D.h"

#pragma once
class Screen
{
public:

	static const float WIDTH;
	static const float HEIGHT;

	sf::RenderWindow* window;

	Screen();

	void Draw(sf::Sprite sprite);

	Vec2D* TopLeft();

	Vec2D* TopCenter();

	Vec2D* TopRight();

	Vec2D* MidLeft();

	Vec2D* MidCenter();

	Vec2D* MidRight();

	Vec2D* BottomLeft();

	Vec2D* BottomCenter();

	Vec2D* BottomRight();

	~Screen();
};

