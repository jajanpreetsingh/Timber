#include "SpriteGameObject.h"
#include "Branch.h"
#include <vector>

#pragma once

class Tree : public SpriteGameObject
{
private:

	std::vector<Branch> branches;

public:

	Tree(sf::Texture tex, sf::Texture branchTex, Pivot piv = Pivot::TopLeft, int branchCount = 0);

	void Update();

	void Draw(sf::RenderWindow* win);

	~Tree();
};