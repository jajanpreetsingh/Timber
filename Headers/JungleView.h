#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BaseView.h"
#include "Cloud.h"
#include "Bee.h"
#include "Word.h"
#include "Utils.h"
#include "Tree.h"
#include "LoadedAssets.h"
#include "AnimatedSpriteObject.h"
#include "Vertices.h"

using namespace sf;

class JungleView : public BaseView
{
public:

	SpriteGameObject* bg = NULL;
	Bee* bee = NULL;
	Tree* tree = NULL;
	Cloud** c;
	Text* score = NULL;
	Font komika;
	Vertices* bgvert;
	Sound beeSound;
	Shader bgShader;

	AnimatedSpriteObject* combee = NULL;

	JungleView(sf::RenderWindow* win, sf::FloatRect& rect); 
	
	void Update(float dtInSeconds);

	void InitBackground();

	void InitText();

	void InitTree();

	void InitClouds();

	void InitSmallBee();

	void InitAnimatedBee();
};

