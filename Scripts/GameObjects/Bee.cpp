#include "Bee.h"
#include "Utils.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>

Bee::Bee(sf::Texture tex, Pivot piv) : SpriteGameObject(tex, piv)
{
	IsActive = false;
}

void Bee::Update()
{
	if (!IsActive)
	{
		float height = Utils::GetRandom(300, 700);

		SetPos(Screen::WIDTH, height);
		IsActive = true;
	}
	else
	{
		int nextXSpeed = Utils::GetRandom(-8, 4); // more tendency to go left
		int nextYSpeed = Utils::GetRandom(-4, 8); // more tendency to come down

		SetScale(nextXSpeed <= 0 ? 1 : -1, 1); // face left/right acc to xspeed

		SetSpeed(nextXSpeed, nextYSpeed);
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
