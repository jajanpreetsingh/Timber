#pragma once

#include "Vertices.h"

Vertices::Vertices(int noOfElements, int prim)
{
	xpos = 0;
	ypos = 0;
	w = 0;
	h = 0;

	primitive = prim;

	size = noOfElements * primitive;

	points = new sf::VertexArray(sf::Quads, size);

	points->resize(size);
}

sf::Vertex& Vertices::operator[](int index)
{
	return (*points)[index];
}

void Vertices::ShiftTexture(float x, float y, MotionType motion)
{
	for (int i = 0; i < points->getVertexCount(); i++)
	{
		float newX = (*points)[i].texCoords.x + x;
		float newY = (*points)[i].texCoords.y;

		if (motion == MotionType::Circular)
		{
			if (newX > w + xpos)
			{
				newX = xpos + x;
			}
			else if (newX < xpos)
			{
				newX = xpos + w - x;
			}
		}

		(*points)[i].texCoords = *new sf::Vector2f(newX, newY);
	}
}

void Vertices::SetBounds(float posx, float posy, float width, float height)
{
	xpos = posx;
	ypos = posy;
	w = width;
	h = height;
}
