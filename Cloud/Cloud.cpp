#include "Cloud.h"
#include "Utils.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>

Cloud::Cloud(std::string filename) :SpriteGameObject(filename)
{
}

Cloud::Cloud(sf::Texture tex) : SpriteGameObject(tex)
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

		if (GetPos()->x > Screen::WIDTH + GetBounds()->x / 2)
		{
			IsActive = false;
		}
	}
}

Cloud::~Cloud()
{
}