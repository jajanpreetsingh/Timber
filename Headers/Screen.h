#include <SFML/Graphics.hpp>
#include "Vec2D.h"

#pragma once
class Screen
{
public:

	static const unsigned int WIDTH;
	static const unsigned int HEIGHT;

	sf::RenderWindow* window;

	Screen();

	void Draw(sf::Sprite sprite);

	static Vec2D* TopLeft();

	static Vec2D* TopCenter();

	static Vec2D* TopRight();

	static Vec2D* MidLeft();

	static Vec2D* MidCenter();

	static Vec2D* MidRight();

	static Vec2D* BottomLeft();

	static Vec2D* BottomCenter();

	static Vec2D* BottomRight();

	~Screen();
};

