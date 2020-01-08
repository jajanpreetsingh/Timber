#pragma once

#include "BaseView.h"

BaseView::BaseView(sf::RenderWindow* win, sf::FloatRect* rect) : sf::View(*rect)
{
	window = win;
}

void BaseView::Update(sf::Clock clock)
{
}

SpriteGameObject* BaseView::Instantiate(SpriteGameObject* object)
{
	gameObjects.push_back(object);

	object->SetParentView(this);

	return object;
}
