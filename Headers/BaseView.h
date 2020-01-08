#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteGameObject.h"

class SpriteGameObject;

class BaseView : public sf::View
{
protected:

	sf::RenderWindow* window;

	std::vector<SpriteGameObject*> gameObjects;

public:

	BaseView(sf::RenderWindow* win, sf::FloatRect* rect);

	virtual void Update(sf::Clock clock);

	virtual SpriteGameObject* Instantiate(SpriteGameObject* object);
};