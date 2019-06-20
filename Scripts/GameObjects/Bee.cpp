#include "Bee.h"
#include "Utils.h"
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Bee::Bee(std::string filename) : SpriteGameObject(filename)
{
}

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
		int nextHeight = Utils::GetRandom(0, 30);
		int dir = Utils::GetRandom(20, 50);

		nextHeight *= (dir == 0 ? 1 : -1);

		SetSpeed(-10, nextHeight);
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
