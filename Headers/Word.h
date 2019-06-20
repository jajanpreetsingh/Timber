#include <SFML/Graphics.hpp>

#pragma once
class Word
{
private:

	Vec2D* currentPos = NULL;

	void SetOrigin(Pivot piv);

	sf::Font* font;

public:

	sf::Text* Message;

	Word(std::string text, sf::Font f, unsigned int charSize, Pivot piv = Pivot::TopLeft);

	void ChangeFont(sf::Font font);

	void ChangeSize(unsigned int size);

	Vec2D* GetBounds();

	void SetPos(float x, float y); 
	
	void SetPos(Vec2D* pos);

	Vec2D* GetPos();

	void operator=(std::string text);

	~Word();
};