#include "AnimatedSpriteObject.h"

AnimatedSpriteObject::AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv) : SpriteGameObject(texArray[0], piv)
{
	animationStates.push_back("default");

	stateSprites["default"] = texArray;

	currentSpriteIndex = 0;

	currentStateSprites = texArray;
}

void AnimatedSpriteObject::Update()
{
	if (currentSpriteIndex >= currentStateSprites.size())
		currentSpriteIndex = 0;

	Sprite->setTexture(currentStateSprites[currentSpriteIndex]);

	++currentSpriteIndex;
}

void AnimatedSpriteObject::ChangeState(std::string stateName)
{
	if (std::find(animationStates.begin(), animationStates.end(), stateName) != animationStates.end())
	{
		currentSpriteIndex = 0;
		currentStateSprites = stateSprites[stateName];
	}
}

void AnimatedSpriteObject::AddAnimationState(std::string stateName, std::vector<sf::Texture> sprites)
{
	if (std::find(animationStates.begin(), animationStates.end(), stateName) != animationStates.end())
		return;

	animationStates.push_back(stateName);
	stateSprites[stateName] = sprites;
}

AnimatedSpriteObject::~AnimatedSpriteObject()
{
}
