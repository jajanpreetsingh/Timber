#pragma once

#include <Vec2D.h>
#include <Pivot.h>
#include <BaseView.h>
#include <Updatable.h>

class BaseView;

class SpriteGameObject : public sf::Sprite, public Updatable
{
private:

	BaseView* parentView;

	Vec2D* currentPos = NULL;

	void SetOrigin(Pivot piv);

public:

	bool IsActive;
	Vec2D* Speed;

	sf::Texture Tex;

	SpriteGameObject(sf::Texture& tex, Pivot piv = Pivot::TopLeft);

	void SetPos(float x, float y);

	void SetPos(Vec2D* pos);

	void SetScale(float x, float y);

	void SetParentView(BaseView* view);

	BaseView* GetParentView();

	void SetSpeed(float x, float y);

	Vec2D* GetPos();

	Vec2D* GetBounds();

	virtual void Update(float dtInSeconds);

	virtual void Move();

	bool IsOutOfScreen();

	void Draw(sf::RenderWindow* win);

	~SpriteGameObject();
};

