#include "Tree.h"
#include "Utils.h"
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Tree::Tree(sf::Texture tex, sf::Texture branchTex, Pivot piv, int branchCount) : SpriteGameObject(tex, piv)
{
	float top = GetPos()->y - GetBounds()->y / 2;

	std::cout << "top : " << top << "    height : " << GetBounds()->x << std::endl;

	for (int i = 0; i < branchCount; i++)
	{
		Branch* br = new Branch(branchTex, i % 2 == 0 ? 1 : -1, Pivot::MidLeft);

		br->tree = this;

		br->SetPos(GetPos());

		branches.push_back(*br);
	}
}

void Tree::Update()
{
}

void Tree::Draw(sf::RenderWindow* win)
{
	win->draw(*Sprite);

	for (int i = 0; i < branches.capacity(); i++)
	{
		win->draw(*branches[i].Sprite);
	}
}

Tree::~Tree()
{
}