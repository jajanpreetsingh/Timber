#include <SFML/Graphics.hpp>

#pragma once
class Word
{
private:

	Vec2D* currentPos = NULL;

public:

	sf::Text* Message;

	Word(std::string text, sf::Font font, unsigned int charSize);

	void ChangeFont(sf::Font font);

	void ChangeSize(unsigned int size);

	Vec2D* GetBounds();

	void SetPos(float x, float y);

	Vec2D* GetPos();

	void operator=(std::string text);

	~Word();
};