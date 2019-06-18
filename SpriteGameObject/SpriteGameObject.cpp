#include <iostream>
#include <SFML/Graphics.hpp>
#include "SpriteGameObject.h"

SpriteGameObject::SpriteGameObject(std::string filename)
{
	currentPos = new Vec2D(0, 0);

	Tex.loadFromFile(filename);
	Sprite = new sf::Sprite(Tex);
	IsActive = false;
	Speed = new Vec2D(0, 0);

	Sprite->setOrigin(GetBounds()->x / 2, GetBounds()->y / 2);

	SetPos(0, 0);

	Sprite->setOrigin(GetBounds()->x / 2, GetBounds()->y / 2);
}

SpriteGameObject::SpriteGameObject(sf::Texture tex)
{
	currentPos = new Vec2D(0, 0);

	Tex = tex;
	Sprite = new sf::Sprite(Tex);
	IsActive = false;
	Speed = new Vec2D(0, 0);

	SetPos(0, 0);

	Sprite->setOrigin(GetBounds()->x / 2, GetBounds()->y / 2);
}

sf::Texture SpriteGameObject::GetTexture(std::string filename)
{
	sf::Texture t;

	t.loadFromFile(filename);

	return t;
}

void SpriteGameObject::SetPos(float x, float y)
{
	currentPos = new Vec2D(x, y);

	Sprite->setPosition(x, y);
}

void SpriteGameObject::SetPos(Vec2D * pos)
{
	SetPos(pos->x, pos->y);
}

void SpriteGameObject::SetScale(float x, float y)
{
	Sprite->setScale(x, y);
}

void SpriteGameObject::SetSpeed(float x, float y)
{
	Speed = new Vec2D(x, y);
}

Vec2D* SpriteGameObject::GetPos()
{
	return currentPos;
}

Vec2D* SpriteGameObject::GetBounds()
{
	sf::FloatRect vt = Sprite->getGlobalBounds();
	return new Vec2D(vt.width, vt.height);
}

void SpriteGameObject::Update()
{

}

void SpriteGameObject::Draw(sf::RenderWindow * win)
{
	win->draw(*Sprite);
}

void SpriteGameObject::Move()
{
	Sprite->move(Speed->x, Speed->y);
}

SpriteGameObject::~SpriteGameObject()
{
}
