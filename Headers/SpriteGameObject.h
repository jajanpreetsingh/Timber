#include "Vec2D.h"

#pragma once
class SpriteGameObject
{
private:

	Vec2D* currentPos = NULL;

public:

	bool IsActive;
	Vec2D* Speed;

	sf::Texture Tex;
	sf::Sprite* Sprite;

	void SetPos(float x, float y);

	void SetPos(Vec2D* pos);

	void SetScale(float x, float y);

	void SetSpeed(float x, float y);

	SpriteGameObject(std::string filename);

	SpriteGameObject(sf::Texture tex);

	static sf::Texture GetTexture(std::string filename);

	Vec2D* GetPos();

	Vec2D* GetBounds();

	void Update();

	void Move();

	void Draw(sf::RenderWindow* win);

	~SpriteGameObject();
};

