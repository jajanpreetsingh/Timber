#include "SpriteGameObject.h"
#include <vector>
#include <string>
#include <map>

#pragma once
class AnimatedSpriteObject : public SpriteGameObject
{
private:
	std::vector<std::string> animationStates;

	std::map<std::string, std::vector<sf::Texture>> stateSprites;

public:

	AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv = Pivot::TopLeft);

	void Update();

	~AnimatedSpriteObject();
};