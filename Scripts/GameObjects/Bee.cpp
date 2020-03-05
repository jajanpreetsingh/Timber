#pragma once

#include <SFML/Graphics.hpp>
#include <Bee.h>
#include <Utils.h>
#include <Screen.h>
#include <SFML/Audio/Listener.hpp>

Bee::Bee(sf::Texture& tex, Pivot piv) : SpriteGameObject(tex, piv)
{
	IsActive = false;
}

void Bee::Update(float dtInSeconds)
{
	if (!IsActive)
	{
		float height = Utils::GetRandom(300, 700);

		SetPos(Screen::WIDTH, height);
		IsActive = true;
	}
	else
	{
		sf::Listener::setPosition(GetPos()->x, GetPos()->y, 0);

		int nextXSpeed = Utils::GetRandom(-8, 4); // more tendency to go left
		int nextYSpeed = Utils::GetRandom(-4, 8); // more tendency to come down

		float nextX = (float)nextXSpeed / 10.0f;
		float nextY = (float)nextYSpeed / 10.0f;
 
		SetScale(nextXSpeed <= 0 ? 1 : -1, 1); // face left/right acc to xspeed

		SetSpeed(nextX, nextY);
		Move();

		if (IsOutOfScreen())
		{
			IsActive = false;
		}
	}
}


Bee::~Bee()
{
}
