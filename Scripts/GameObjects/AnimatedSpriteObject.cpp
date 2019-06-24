#include "AnimatedSpriteObject.h"

AnimatedSpriteObject::AnimatedSpriteObject(std::vector<sf::Texture> texArray, Pivot piv) :SpriteGameObject(texArray[0], piv)
{
	animationStates.push_back("default");


}

void AnimatedSpriteObject::Update()
{
}

AnimatedSpriteObject::~AnimatedSpriteObject()
{
}
