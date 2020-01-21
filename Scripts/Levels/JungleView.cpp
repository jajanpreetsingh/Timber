#pragma once

#include "JungleView.h"
#include "Screen.h"

JungleView::JungleView(sf::RenderWindow* win, sf::FloatRect& rect) : BaseView(win, rect)
{
	InitBackground();

	InitAnimatedBee();

	InitSmallBee();

	InitClouds();

	InitText();
}

void JungleView::Update(Clock clock)
{
	BaseView::Update(clock);

	Time dt = clock.restart();

	bgvert->ShiftTexture(2, 0);

	window->clear();

	window->draw(*bgvert->points, LoadedAssets::GetTexture(TextureType::All));

	Draw();

	window->display();
}

void JungleView::InitBackground()
{
	bgvert = new Vertices(1, 4);

	bgvert->SetBounds(0, 0, 2598, 1457);

	(*bgvert->points)[0].position = *static_cast<Vector2f*>(Screen::TopLeft());
	(*bgvert->points)[1].position = *static_cast<Vector2f*>(Screen::TopRight());
	(*bgvert->points)[2].position = *static_cast<Vector2f*>(Screen::BottomRight());
	(*bgvert->points)[3].position = *static_cast<Vector2f*>(Screen::BottomLeft());

	//2598; 2974; 928; 577

	(*bgvert->points)[0].texCoords = *new sf::Vector2f(0, 0);
	(*bgvert->points)[1].texCoords = *new sf::Vector2f(0 + 2598, 0);
	(*bgvert->points)[2].texCoords = *new sf::Vector2f(0 + 2598, 0 + 1457);
	(*bgvert->points)[3].texCoords = *new sf::Vector2f(0, 0 + 1457);

	//bg = Instantiate(new SpriteGameObject(*LoadedAssets::GetTexture(TextureType::Background), Pivot::MidCenter));

	//Vec2D* b = bg->GetBounds();

	//bg->SetScale(Screen::WIDTH / b->x, Screen::HEIGHT / b->y);

	//bg->SetPos(Screen::MidCenter());
	
}

void JungleView::InitTree()
{
	tree = static_cast<Tree*>(Instantiate(new Tree(*LoadedAssets::GetTexture(TextureType::Tree),
		*LoadedAssets::GetTexture(TextureType::Branch),
		Pivot::MidCenter, 0)));

	tree->SetPos(Screen::MidCenter()->x, Screen::MidCenter()->y);

	tree->AddBranches(4);
}

void JungleView::InitClouds()
{
	int size = 8;
	c = new Cloud * [size];

	for (int i = 0; i < size; i++)
	{
		c[i] = static_cast<Cloud*>(Instantiate(new Cloud(*LoadedAssets::GetTexture(TextureType::Cloud2), Pivot::MidCenter)));
	}
}

void JungleView::InitSmallBee()
{
	bee = static_cast<Bee*>(Instantiate(new Bee(*LoadedAssets::GetTexture(TextureType::Bee), Pivot::MidCenter)));
}

void JungleView::InitText()
{
	komika = *LoadedAssets::GetFont(FontType::Komika);

	score = new Text("score : 0", komika, 40);

	drawableObjects.push_back(score);

	Vector2f tbound = Vector2f(0, score->getLocalBounds().height);

	score->setOrigin(tbound);

	float lpad = 20;
	float tpad = 20;

	float xpos = Screen::TopLeft()->x + lpad;
	float ypos = Screen::TopLeft()->y + score->getLocalBounds().height + tpad;

	score->setPosition(xpos, ypos);
}

void JungleView::InitAnimatedBee()
{
	std::vector<std::string> fileNames;

	for (int i = 0; i < 30; i++)
	{
		std::string name = "bee/" + std::to_string(i) + "bee.png";
		fileNames.push_back(name);
	}

	Sound s;
	s.setBuffer(*LoadedAssets::GetSoundBuffer(SoundType::Chop));

	s.play();

	combee = static_cast<AnimatedSpriteObject*>(Instantiate(new AnimatedSpriteObject(LoadedAssets::GetTextures(fileNames), Pivot::MidCenter)));
	combee->SetPos(Screen::MidCenter());
	combee->ChangeAnimationSpeed(30);
}
