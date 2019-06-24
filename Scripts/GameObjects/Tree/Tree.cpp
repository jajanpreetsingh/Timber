#include "Tree.h"
#include "Utils.h"
#include "Screen.h"
#include <iostream>
#include <SFML/Graphics.hpp>

Tree::Tree(sf::Texture tex, sf::Texture branchTex, Pivot piv, int branchCount) : SpriteGameObject(tex, piv)
{
	SetScale(2, 2);
	Vec2D* pos = Screen::MidCenter();
	SetPos(pos);

	float ht = GetBounds()->y;
	float top = pos->y - (ht / 2);

	for (int i = 0; i < branchCount; i++)
	{
		int dir = i % 2 == 0 ? 1 : -1;
		Branch* br = new Branch(branchTex, dir, Pivot::MidLeft);

		br->tree = this;

		br->SetPos(pos->x + (dir * GetBounds()->x / 2), top + i * (ht / branchCount));

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