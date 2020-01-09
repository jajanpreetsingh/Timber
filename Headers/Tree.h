#include "SpriteGameObject.h"
#include "Branch.h"
#include <vector>

#pragma once

class Tree : public SpriteGameObject
{
private:

	std::vector<Branch> branches;

	sf::Texture* branchTex;

public:

	Tree(sf::Texture& tex, sf::Texture& branchTex, Pivot piv = Pivot::TopLeft, int branchCount = 0);

	void Update();

	void AddBranches(int numberOfBranches);

	void Draw(sf::RenderWindow* win);

	~Tree();
};