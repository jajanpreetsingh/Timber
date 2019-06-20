#include "Vec2D.h"
#include "Pivot.h"
#include "Word.h"

Word::Word(std::string text, sf::Font f, unsigned int charSize, Pivot piv)
{
	font = &f;
	Message = new sf::Text(text, *font, charSize);
	Vec2D* v = GetBounds();

	SetOrigin(piv);
}



void Word::SetOrigin(Pivot piv)
{
	Vec2D* b = GetBounds();

	switch (piv)
	{
	case Pivot::TopLeft:
		Message->setOrigin(0, 0);
		break;

	case Pivot::TopCenter:
		Message->setOrigin(b->x / 2, 0);
		break;

	case Pivot::TopRight:

		Message->setOrigin(b->x, 0);
		break;



	case Pivot::MidLeft:

		Message->setOrigin(0, b->y / 2);
		break;

	case Pivot::MidCenter:

		Message->setOrigin(b->x / 2, b->y / 2);
		break;

	case Pivot::MidRight:

		Message->setOrigin(b->x, b->y / 2);
		break;



	case Pivot::BottomLeft:

		Message->setOrigin(0, b->y);
		break;

	case Pivot::BottomCenter:

		Message->setOrigin(b->x / 2, b->y);
		break;

	case Pivot::BottomRight:

		Message->setOrigin(b->x, b->y);
		break;

	default:
		Message->setOrigin(0, 0);
		break;
	}
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
	currentPos = new Vec2D(x, y);

	Message->setPosition(x, y);
}

void Word::SetPos(Vec2D* pos)
{
	SetPos(pos->x, pos->y);
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