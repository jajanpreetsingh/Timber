#include <iostream>
#include <SFML/Graphics.hpp>
#include "Utils.h"

Utils::Utils()
{
}

int Utils::GetRandom(int min, int max)
{
	if (max < min)
	{
		int temp = max;
		max = min;
		min = max;
	}

	return min + (rand() % (max - min));
}


Utils::~Utils()
{
}
