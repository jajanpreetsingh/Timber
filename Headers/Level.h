#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteGameObject.h"

class SpriteGameObject;

class Level : public sf::View
{
private:
	sf::Window* window;

	std::vector<SpriteGameObject*> gameObjects;

public:

	Level(sf::Window* win, sf::FloatRect& rect);

	void Instantiate(SpriteGameObject* object);

	void AddToChildren(SpriteGameObject* object);
};