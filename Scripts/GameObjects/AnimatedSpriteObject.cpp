#include "AnimatedSpriteObject.h"

AnimatedSpriteObject::AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv) : SpriteGameObject(texArray[0], piv)
{
	animationStates.push_back("default");

	stateSprites["default"] = texArray;

	currentSpriteIndex = 0;

	currentStateSprites = texArray;

	animationScale = 20;

	clock.restart();
}

void AnimatedSpriteObject::Update()
{
	if (spriteChangedTimeElapsed >= (1 / animationScale))
	{
		++currentSpriteIndex;
		spriteChangedTimeElapsed = 0;
	}

	if (currentSpriteIndex >= currentStateSprites.size())
		currentSpriteIndex = 0;

	Sprite->setTexture(currentStateSprites[currentSpriteIndex]);

	spriteChangedTimeElapsed += clock.restart().asSeconds();
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

void AnimatedSpriteObject::ChangeAnimationSpeed(float newScale)
{
	animationScale = newScale;
}

AnimatedSpriteObject::~AnimatedSpriteObject()
{
}
