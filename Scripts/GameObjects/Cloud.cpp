#include "Cloud.h"
#include "Utils.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>

Cloud::Cloud(sf::Texture tex, Pivot piv) : SpriteGameObject(tex, piv)
{
	IsActive = false;

	SetScale(-1, 1);
}

void Cloud::Update()
{
	if (!IsActive)
	{
		Speed = new Vec2D((float)Utils::GetRandom(1, 3) / 10.0f, 0);

		float height = Utils::GetRandom(100, 400);

		SetPos(-GetBounds()->x / 2, height);
		IsActive = true;
	}
	else
	{
		Move();

		if (IsOutOfScreen())
		{
			IsActive = false;
		}
	}
}

Cloud::~Cloud()
{
}