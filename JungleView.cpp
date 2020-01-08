#pragma once

#include "JungleView.h"
#include "Screen.h"

JungleView::JungleView(sf::RenderWindow* win, sf::FloatRect* rect) : BaseView(win, rect)
{
	bg = Instantiate(new SpriteGameObject(LoadedAssets::GetTexture(TextureType::Background), Pivot::MidCenter));

	Vec2D* b = bg->GetBounds();

	bg->SetScale(Screen::WIDTH / b->x, Screen::HEIGHT / b->y);

	bg->SetPos(Screen::MidCenter());

	// Make a tree sprite
	tree = new Tree(LoadedAssets::GetTexture(TextureType::Tree),
		LoadedAssets::GetTexture(TextureType::Branch),
		Pivot::MidCenter, 0);

	tree->SetPos(Screen::MidCenter()->x, Screen::MidCenter()->y);

	tree->AddBranches(6);
	tree->AddBranches(2);

	InitAnimatedBee();

	bee = new Bee(LoadedAssets::GetTexture(TextureType::Bee), Pivot::MidCenter);

	int size = 8;
	c = new Cloud * [size];

	for (int i = 0; i < size; i++)
	{
		c[i] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud2), Pivot::MidCenter);
	}

	InitText();
}

void JungleView::Update(Clock clock)
{
	Time dt = clock.restart();

	//setRotation(dt.asSeconds() * 360);

	bee->Update();

	for (int i = 0; i < 3; i++)
	{
		c[i]->Update();
	}

	combee->Update();

	window->clear();

	bg->Draw(window);

	for (int i = 0; i < 3; i++)
	{
		c[i]->Draw(window);
	}

	tree->Draw(window);

	bee->Draw(window);

	combee->Draw(window);

	window->draw(*(score));

	window->display();
}

void JungleView::InitText()
{
	komika = LoadedAssets::GetFont(FontType::Komika);

	score = new Text("score : 0", komika, 40);

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
	s.setBuffer(LoadedAssets::GetSoundBuffer(SoundType::Chop));

	s.play();

	combee = new AnimatedSpriteObject(LoadedAssets::GetTextures(fileNames), Pivot::MidCenter);
	combee->SetPos(Screen::MidCenter());
	combee->ChangeAnimationSpeed(30);
}
