#pragma once

#include "Level.h"

Level::Level(sf::Window* win, sf::FloatRect& rect) : sf::View(rect)
{
	window = win;
}

void Level::Instantiate(SpriteGameObject* object)
{
	AddToChildren(object);
}

void Level::AddToChildren(SpriteGameObject* object)
{
	gameObjects.push_back(object);
}
