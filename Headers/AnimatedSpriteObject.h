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

	int direction;

	std::vector<sf::Texture> currentStateSprites;

	float spriteChangedTimeElapsed;

	sf::Clock clock;

public:

	AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv = Pivot::TopLeft);

	void Update();

	void ChangeState(std::string stateName);

	void AddAnimationState(std::string stateName, std::vector<sf::Texture> sprites);

	void ChangeAnimationSpeed(float newScale);

	void Reverse();

	~AnimatedSpriteObject();
};