#pragma once

#include <SFML/Graphics.hpp>

class Rendrable
{
public:

	//virtual void Draw() = 0;

	virtual void Draw(sf::RenderWindow* window) = 0;
};