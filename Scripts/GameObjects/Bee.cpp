#include "Bee.h"
#include "Utils.h"
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Bee::Bee(sf::Texture tex, Pivot piv) : SpriteGameObject(tex, piv)
{

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
		int nextHeight = Utils::GetRandom(-2, 4);

		SetSpeed(-1, nextHeight);
		Move();

		if (GetPos()->x < 0)
		{
			IsActive = false;
		}
	}
}


Bee::~Bee()
{
}
