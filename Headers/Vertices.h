#pragma once

#include <SFML/Graphics.hpp>
#include <Vec2D.h>

enum class MotionType
{
	Circular,
};

class Vertices
{
private:
	sf::PrimitiveType primitive;

	int verticesPerElement;

	int size;

	float xpos, ypos, width, height;

public:

	sf::VertexArray* points;

	Vertices(int noOfElements, int vertPerElement, sf::PrimitiveType prim);

	sf::Vertex &operator[](int index);

	void ShiftTexture(float x, float y, MotionType motion = MotionType::Circular);

	void SetBounds(float posx, float posy, float width, float height);
};

