#pragma once

#include "Vertices.h"

Vertices::Vertices(int noOfElements, int vertPerElement, sf::PrimitiveType prim)
{
	xpos = 0;
	ypos = 0;
	width = 0;
	height = 0;

	primitive = prim;
	vertPerElement = vertPerElement;

	size = noOfElements * vertPerElement;

	points = new sf::VertexArray(primitive, size);
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
			if (newX > width + xpos)
			{
				newX = xpos + x;
			}
			else if (newX < xpos)
			{
				newX = xpos + width - x;
			}
		}

		(*points)[i].texCoords = *new sf::Vector2f(newX, newY);
	}
}

void Vertices::SetBounds(float posx, float posy, float width, float height)
{
	xpos = posx;
	ypos = posy;
	this->width = width;
	this->height = height;
}
