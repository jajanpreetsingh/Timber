#include "SpriteGameObject.h"

#pragma once

class Branch : public SpriteGameObject
{
	int direction;

public:

	SpriteGameObject* tree;

	Branch(sf::Texture& tex, int dir = 1, Pivot piv = Pivot::TopLeft);

	void Update();

	~Branch();
};