#pragma once

#include <SFML/Graphics.hpp>
#include "SpriteGameObject.h"

class SpriteGameObject;

class BaseView : public sf::View
{
protected:

	sf::RenderWindow* window;

	std::vector<SpriteGameObject*> gameObjects;

	std::vector<sf::Drawable*> drawableObjects;

public:

	BaseView(sf::RenderWindow* win, sf::FloatRect& rect);

	virtual void Update(float dtInSeconds);

	virtual void Draw();

	virtual SpriteGameObject* Instantiate(SpriteGameObject* object);
};