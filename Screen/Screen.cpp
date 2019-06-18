#include "Screen.h"
#include <SFML/Graphics.hpp>

const unsigned int Screen::WIDTH = 3200;
const unsigned int Screen::HEIGHT = 1800;

Screen::Screen()
{
	sf::VideoMode vm(Screen::WIDTH, Screen::HEIGHT);

	window = new sf::RenderWindow(vm, "Timber!!!", sf::Style::Default);
}

void Screen::Draw(sf::Sprite sprite)
{
	window->draw(sprite);
}

Vec2D* Screen::TopLeft()
{
	return new Vec2D(0, 0);
}

Vec2D* Screen::TopCenter()
{
	return new Vec2D(WIDTH / 2, 0);
}

Vec2D* Screen::TopRight()
{
	return new Vec2D(WIDTH, 0);
}

Vec2D* Screen::MidLeft()
{
	return new Vec2D(0, HEIGHT / 2);
}

Vec2D* Screen::MidCenter()
{
	return new Vec2D(WIDTH / 2, HEIGHT / 2);
}

Vec2D* Screen::MidRight()
{
	return new Vec2D(WIDTH, HEIGHT / 2);
}

Vec2D* Screen::BottomLeft()
{
	return new Vec2D(0, HEIGHT);
}

Vec2D* Screen::BottomCenter()
{
	return new Vec2D(WIDTH / 2, HEIGHT);
}

Vec2D* Screen::BottomRight()
{
	return new Vec2D(WIDTH, HEIGHT);
}

Screen::~Screen()
{
}