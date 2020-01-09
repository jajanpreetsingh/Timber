#include "Tree.h"
#include "Utils.h"
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Tree::Tree(sf::Texture& tex, sf::Texture& branchTex, Pivot piv, int branchCount) : SpriteGameObject(tex, piv)
{
	this->branchTex = &branchTex;
}

void Tree::Update()
{
}

void Tree::AddBranches(int numberOfBranches)
{
	Vec2D* pos = GetPos();

	float ht = GetBounds()->y;
	float top = pos->y - (ht / 2);

	for (int i = 0; i < numberOfBranches; i++)
	{
		int dir = i % 2 == 0 ? 1 : -1;
		Branch* br = static_cast<Branch*>(GetParentView()->Instantiate(new Branch(*branchTex, dir, Pivot::MidLeft)));

		br->SetParentView(GetParentView());

		br->tree = this;

		branches.push_back(*br);
	}

	for (int i = 0; i < branches.size(); i++)
	{
		int dir = i % 2 == 0 ? 1 : -1;

		branches[i].SetScale(dir, 1);

		branches[i].SetPos(pos->x + (dir * GetBounds()->x / 2), top + i * (ht / branches.size()));
	}
}

void Tree::Draw(sf::RenderWindow* win)
{
	win->draw(*this);

	for (int i = 0; i < branches.size(); i++)
	{
		win->draw(branches[i]);
	}
}

Tree::~Tree()
{
}