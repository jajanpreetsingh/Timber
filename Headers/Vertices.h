#pragma once

#include <SFML/Graphics.hpp>
#include <Vec2D.h>

class Vertices
{
private:
	int primitive;

	int size;

	float xpos, ypos, w, h;

public:

	enum MotionType
	{
		Circular,
	};

	sf::VertexArray* points;

	Vertices(int noOfElements, int prim);

	sf::Vertex &operator[](int index);

	void ShiftTexture(float x, float y, MotionType motion = MotionType::Circular);

	void SetBounds(float posx, float posy, float width, float height);
};

