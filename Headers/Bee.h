#include "SpriteGameObject.h"

#pragma once
class Bee : public SpriteGameObject
{
public:
	Bee(std::string filename);

	Bee(sf::Texture tex, Pivot piv = Pivot::TopLeft);

	void Update();

	~Bee();
};

