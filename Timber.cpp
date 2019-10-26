#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vec2D.h"
#include "Cloud.h"
#include "Bee.h"
#include "Utils.h"
#include "Tree.h"
#include "LoadedAssets.h"
#include "Screen.h"
#include "Word.h"
#include "AnimatedSpriteObject.h"

using namespace sf;

void Update(Clock clock);
void ProcessInput();
void SetupScreen();
void InitText();
void InitAnimatedBee();

bool paused = false;

Screen* screen = NULL;
SpriteGameObject* bg = NULL;
Bee* bee = NULL;
Tree* tree = NULL;
Cloud* c[3];
Text* score = NULL;
Font komika;

AnimatedSpriteObject* combee = NULL;

SpriteGameObject* gameObjects[];

std::map<TextureType, sf::Texture> LoadedAssets::Textures;

std::map<FontType, sf::Font> LoadedAssets::Fonts;

LoadedAssets* assets;

std::map<SoundType, sf::SoundBuffer> LoadedAssets::Sounds;

int main()
{
	// Create a video mode object
	SetupScreen();

	srand(time(0));

	assets = new LoadedAssets();

	bg = new SpriteGameObject(LoadedAssets::GetTexture(TextureType::Background), Pivot::MidCenter);

	Vec2D* b = bg->GetBounds();

	bg->SetScale(Screen::WIDTH / b->x, Screen::HEIGHT / b->y);

	bg->SetPos(screen->MidCenter());

	// Make a tree sprite
	tree = new Tree(LoadedAssets::GetTexture(TextureType::Tree),
		LoadedAssets::GetTexture(TextureType::Branch),
		Pivot::MidCenter, 0);

	tree->SetPos(screen->MidCenter()->x, screen->MidCenter()->y);

	tree->AddBranches(6);
	tree->AddBranches(2);

	InitAnimatedBee();

	bee = new Bee(LoadedAssets::GetTexture(TextureType::Bee), Pivot::MidCenter);

	c[0] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud), Pivot::MidCenter);
	c[1] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud), Pivot::MidCenter);
	c[2] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud), Pivot::MidCenter);

	InitText();

	Clock clock;

	while (screen->window->isOpen())
	{
		ProcessInput();

		if (!paused)
			Update(clock);
	}
	return 0;
}

void SetupScreen()
{
	screen = new Screen();
}

void ProcessInput()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		screen->window->close();
	}

	if (Keyboard::isKeyPressed(Keyboard::P))
	{
		paused = !paused;
	}
}

void InitText()
{
	komika = LoadedAssets::GetFont(FontType::Komika);

	score = new Text("score : 0", komika, 40);

	Vector2f tbound = Vector2f(0, score->getLocalBounds().height);

	score->setOrigin(tbound);

	float lpad = 20;
	float tpad = 20;

	float xpos = screen->TopLeft()->x + lpad;
	float ypos = screen->TopLeft()->y + score->getLocalBounds().height + tpad;

	score->setPosition(xpos, ypos);
}


void InitAnimatedBee()
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
}

void Update(Clock clock)
{
	Time dt = clock.restart();

	bee->Update();

	for (int i = 0; i < 3; i++)
	{
		c[i]->Update();
	}

	combee->Update();

	combee->ChangeAnimationSpeed(3);

	screen->window->clear();

	bg->Draw(screen->window);

	for (int i = 0; i < 3; i++)
	{
		c[i]->Draw(screen->window);
	}

	tree->Draw(screen->window);

	bee->Draw(screen->window);

	combee->Draw(screen->window);

	screen->window->draw(*(score));

	screen->window->display();
}