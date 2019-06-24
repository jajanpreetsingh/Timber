#include "Cloud.h"
#include "Utils.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>

Cloud::Cloud(sf::Texture tex, Pivot piv) : SpriteGameObject(tex, piv)
{
}

void Cloud::Update()
{
	if (!IsActive)
	{
		Speed = new Vec2D(Utils::GetRandom(3, 5), 0);

		float height = Utils::GetRandom(100, 400);

		SetPos(0, height);
		IsActive = true;
	}
	else
	{
		Move();

		if (GetPos()->x > Screen::WIDTH)
		{
			IsActive = false;
		}
	}
}

Cloud::~Cloud()
{
}