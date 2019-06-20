#include "SpriteGameObject.h"
#include <iostream>
#include <string>

#pragma once

class Cloud : public SpriteGameObject
{

public:

	Cloud(std::string filename);

	Cloud(sf::Texture tex, Pivot piv = Pivot::TopLeft);

	void Update();

	~Cloud();
};

