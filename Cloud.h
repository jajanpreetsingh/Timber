#include "SpriteGameObject.h"
#include <iostream>
#include <string>

#pragma once

class Cloud : public SpriteGameObject
{

public:

	Cloud(std::string filename);

	Cloud(sf::Texture tex);

	void Update();

	~Cloud();
};

