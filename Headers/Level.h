#include <SFML/Graphics.hpp>
#include <SpriteGameObject.h>

#pragma once

class Level : sf::View
{
private:
	sf::Window* window;

	std::vector<SpriteGameObject*> gameObjects;

public:

	Level(sf::Window* win, sf::FloatRect& rect);

	void Instantiate(SpriteGameObject* object);

	void AddToChildren(SpriteGameObject* object);
};