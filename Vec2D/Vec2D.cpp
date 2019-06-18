#include "Vec2D.h"

Vec2D::Vec2D(float x, float y) :sf::Vector2f(x, y)
{

}

Vec2D Vec2D::operator=(float x)
{
	return (*(new Vec2D(x, x)));
}

Vec2D Vec2D::operator=(sf::Vector2f v)
{
	return (*(new Vec2D(v.x, v.y)));
}

Vec2D::~Vec2D()
{
}