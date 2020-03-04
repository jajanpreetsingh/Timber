#include <SpriteGameObject.h>

#pragma once
class Bee : public SpriteGameObject
{
private:
	
	const float xSpeed = 7;

public:

	Bee(sf::Texture& tex, Pivot piv = Pivot::TopLeft);

	void Update();

	~Bee();
};

