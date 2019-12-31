#pragma once

#include "Vec2D.h"
#include "Pivot.h"
#include "Level.h"

class Level;

class SpriteGameObject
{
private:

	Level* parentView;

	Vec2D* currentPos = NULL;

	void SetOrigin(Pivot piv);

public:

	bool IsActive;
	Vec2D* Speed;

	sf::Texture Tex;
	sf::Sprite* Sprite;

	SpriteGameObject(sf::Texture tex, Pivot piv = Pivot::TopLeft);

	void SetPos(float x, float y);

	void SetPos(Vec2D* pos);

	void SetScale(float x, float y);

	void SetParentView(Level* view);

	void SetSpeed(float x, float y);

	static sf::Texture GetTexture(std::string filename);

	Vec2D* GetPos();

	Vec2D* GetBounds();

	void Update();

	void Move();

	bool IsOutOfScreen();

	void Draw(sf::RenderWindow* win);

	~SpriteGameObject();
};

