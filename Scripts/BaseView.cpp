#pragma once

#include "BaseView.h"
#include <SFML/Graphics.hpp>

BaseView::BaseView(sf::RenderWindow* win, sf::FloatRect& rect) : sf::View(rect)
{
	this->reset(rect);

	this->setViewport(sf::FloatRect(0, 0, 0.5, 0.5));
	window = win;
}

void BaseView::Update(float dtInSeconds)
{
	if (gameObjects.empty())
	{
		return;
	}

	for (int i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update();
	}
}

void BaseView::Draw()
{
	if (drawableObjects.empty())
	{
		return;
	}

	for (int i = 0; i < drawableObjects.size(); i++)
	{
		window->draw(*drawableObjects[i]);
	}
}

SpriteGameObject* BaseView::Instantiate(SpriteGameObject* object)
{
	gameObjects.push_back(object);

	drawableObjects.push_back(object);

	object->SetParentView(this);

	return object;
}
