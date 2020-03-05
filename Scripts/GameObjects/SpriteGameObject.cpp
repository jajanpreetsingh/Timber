#pragma once

#include <SpriteGameObject.h>
#include <SFML/Graphics.hpp>
#include <Screen.h>

SpriteGameObject::SpriteGameObject(sf::Texture& tex, Pivot piv) : Sprite(tex)
{
	currentPos = new Vec2D(0, 0);

	Tex = tex;
	IsActive = true;
	Speed = new Vec2D(0, 0);

	SetPos(0, 0);

	SetOrigin(piv);
}

void SpriteGameObject::SetOrigin(Pivot piv)
{
	Vec2D* b = GetBounds();

	switch (piv)
	{
	case Pivot::TopLeft:
		setOrigin(0, 0);
		break;

	case Pivot::TopCenter:
		setOrigin(b->x / 2, 0);
		break;

	case Pivot::TopRight:

		setOrigin(b->x, 0);
		break;



	case Pivot::MidLeft:

		setOrigin(0, b->y / 2);
		break;

	case Pivot::MidCenter:

		setOrigin(b->x / 2, b->y / 2);
		break;

	case Pivot::MidRight:

		setOrigin(b->x, b->y / 2);
		break;



	case Pivot::BottomLeft:

		setOrigin(0, b->y);
		break;

	case Pivot::BottomCenter:

		setOrigin(b->x / 2, b->y);
		break;

	case Pivot::BottomRight:

		setOrigin(b->x, b->y);
		break;

	default:
		setOrigin(0, 0);
		break;
	}
}

void SpriteGameObject::SetPos(float x, float y)
{
	currentPos = new Vec2D(x, y);

	setPosition(x, y);
}

void SpriteGameObject::SetPos(Vec2D* pos)
{
	SetPos(pos->x, pos->y);
}

void SpriteGameObject::SetScale(float x, float y)
{
	setScale(x, y);
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
	sf::FloatRect vt = getGlobalBounds();
	return new Vec2D(vt.width, vt.height);
}

void SpriteGameObject::Update(float dtInSeconds)
{

}

void SpriteGameObject::Draw(sf::RenderWindow* win)
{
	if (!IsActive)
	{
		return;
	}

	if (parentView != nullptr)
	{
		win->setView(*parentView);
	}

	win->draw(*this);
}

void SpriteGameObject::SetParentView(BaseView* view)
{
	parentView = view;
}

BaseView* SpriteGameObject::GetParentView()
{
	return parentView;
}

void SpriteGameObject::Move()
{
	move(Speed->x, Speed->y);

	sf::Vector2f v = getPosition();

	currentPos = new Vec2D(v.x, v.y);
}

bool SpriteGameObject::IsOutOfScreen()
{
	sf::FloatRect fr = sf::FloatRect(0, 0, Screen::WIDTH, Screen::HEIGHT);

	return !fr.intersects(getGlobalBounds());
}

SpriteGameObject::~SpriteGameObject()
{
}
