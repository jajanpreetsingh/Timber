#include "SpriteGameObject.h"
#include <vector>
#include <string>
#include <map>

#pragma once
class AnimatedSpriteObject : public SpriteGameObject
{
private:

	float animationScale;//frames or sprites per second

	std::vector<std::string> animationStates;

	std::map<std::string, std::vector<sf::Texture>> stateSprites;

	int currentSpriteIndex;

	std::vector<sf::Texture> currentStateSprites;

public:

	AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv = Pivot::TopLeft);

	void Update();

	void ChangeState(std::string stateName);

	void AddAnimationState(std::string stateName, std::vector<sf::Texture> sprites);

	~AnimatedSpriteObject();
};