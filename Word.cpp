#include "Vec2D.h"
#include "Word.h"

Word::Word(std::string text, sf::Font font, unsigned int charSize)
{
	Message = new sf::Text(text, font, charSize);
	Vec2D* v = GetBounds();

	Message->setOrigin(v->x / 2, v->y / 2);
}

void Word::ChangeFont(sf::Font font)
{
	Message->setFont(font);
}

void Word::ChangeSize(unsigned int size)
{
	Message->setCharacterSize(size);
}

void Word::SetPos(float x, float y)
{
	//Vec2D* v = GetBounds();

	float newX = x;
	float newY = y;

	currentPos = new Vec2D(x, y);

	Message->setPosition(newX, newY);
}

Vec2D* Word::GetPos()
{
	return currentPos;
}

Vec2D* Word::GetBounds()
{
	sf::FloatRect vt = Message->getLocalBounds();

	return new Vec2D(vt.width, vt.height);
}

void Word::operator=(std::string text)
{
	Message->setString(text);
}

Word::~Word()
{
}