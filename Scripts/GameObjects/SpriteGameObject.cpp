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

SpriteGameObject::SpriteGameObject(sf::Texture tex, Pivot piv)
{
	currentPos = new Vec2D(0, 0);

	Tex = tex;
	Sprite = new sf::Sprite(Tex);
	IsActive = false;
	Speed = new Vec2D(0, 0);

	SetPos(0, 0);

	SetOrigin(piv);
}

sf::Texture SpriteGameObject::GetTexture(std::string filename)
{
	sf::Texture t;

	t.loadFromFile(filename);

	return t;
}

void SpriteGameObject::SetOrigin(Pivot piv)
{
	Vec2D* b = GetBounds();

	switch (piv)
	{
	case Pivot::TopLeft:
		Sprite->setOrigin(0, 0);
		break;

	case Pivot::TopCenter:
		Sprite->setOrigin(b->x / 2, 0);
		break;

	case Pivot::TopRight:
		
		Sprite->setOrigin(b->x, 0);
		break;



	case Pivot::MidLeft:
		
		Sprite->setOrigin(0, b->y / 2);
		break;

	case Pivot::MidCenter:
		
		Sprite->setOrigin(b->x / 2, b->y / 2);
		break;

	case Pivot::MidRight:
		
		Sprite->setOrigin(b->x, b->y / 2);
		break;



	case Pivot::BottomLeft:
		
		Sprite->setOrigin(0, b->y);
		break;

	case Pivot::BottomCenter:
		
		Sprite->setOrigin(b->x / 2, b->y);
		break;

	case Pivot::BottomRight:
		
		Sprite->setOrigin(b->x, b->y);
		break;

	default:
		Sprite->setOrigin(0, 0);
		break;
	}
}

void SpriteGameObject::SetPos(float x, float y)
{
	currentPos = new Vec2D(x, y);

	Sprite->setPosition(x, y);
}

void SpriteGameObject::SetPos(Vec2D* pos)
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

void SpriteGameObject::Draw(sf::RenderWindow* win)
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
