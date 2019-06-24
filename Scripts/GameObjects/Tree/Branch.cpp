#include "Branch.h"
#include "Utils.h"
#include "Screen.h"
#include <SFML/Graphics.hpp>

Branch::Branch(sf::Texture tex, int dir, Pivot piv) : SpriteGameObject(tex, piv)
{
	if (dir < 0)
	{
		SetScale(-1, 1);
		
	}
}

void Branch::Update()
{
}

Branch::~Branch()
{
}