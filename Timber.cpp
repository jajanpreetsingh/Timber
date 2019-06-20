#include <iostream>
#include <SFML/Graphics.hpp>
#include "Headers/Vec2D.h"
#include "Headers/Cloud.h"
#include "Headers/Bee.h"
#include "Headers/Utils.h"
#include "Headers/LoadedAssets.h"
#include "Headers/Screen.h"
#include "Headers/Word.h"

using namespace sf;

void Update(Clock clock);
void ProcessInput();
void SetupScreen();
void InitText();

bool paused = false;

Screen* screen = NULL;
SpriteGameObject* bg = NULL;
Bee* bee = NULL;
SpriteGameObject* tree = NULL;
Cloud* c[3];
Text* score = NULL;
Font komika;

SpriteGameObject* gameObjects[];

std::map<TextureType, sf::Texture> LoadedAssets::Textures;

std::map<FontType, sf::Font> LoadedAssets::Fonts;

int main()
{
	// Create a video mode object
	SetupScreen();

	srand(time(0));

	new LoadedAssets();

	bg = new SpriteGameObject(LoadedAssets::GetTexture(TextureType::Background),Pivot::MidCenter);

	Vec2D* b = bg->GetBounds();

	bg->SetScale(Screen::WIDTH / b->x, Screen::HEIGHT / b->y);

	bg->SetPos(screen->MidCenter());

	// Make a tree sprite
	tree = new SpriteGameObject(LoadedAssets::GetTexture(TextureType::Tree), Pivot::MidCenter);
	tree->SetPos(screen->MidCenter()->x, screen->MidCenter()->y);

	bee = new Bee(LoadedAssets::GetTexture(TextureType::Bee), Pivot::MidCenter);

	c[0] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud),Pivot::MidCenter);
	c[1] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud),Pivot::MidCenter);
	c[2] = new Cloud(LoadedAssets::GetTexture(TextureType::Cloud),Pivot::MidCenter);

	InitText();

	Clock clock;

	while (screen->window->isOpen())
	{
		ProcessInput();

		if (!paused)
			Update(clock);
		else
		{
			continue;
		}
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

	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		paused = !paused;
	}
}

void InitText()
{
	komika.loadFromFile("fonts/KOMIKAP_.ttf");

	score = new Text("score : 0", komika, 40);

	//Vector2f tbound = Vector2f(score->getLocalBounds().width / 2, score->getLocalBounds().height / 2);

	//score->setOrigin(tbound);

	float lpad = 20;
	float tpad = 20;

	float xpos = screen->TopLeft()->x + lpad;
	float ypos = screen->TopLeft()->y + tpad;

	score->setPosition(xpos, ypos);
}

void Update(Clock clock)
{
	Time dt = clock.restart();

	bee->Update();

	for (int i = 0; i < 3; i++)
	{
		c[i]->Update();
	}

	screen->window->clear();

	bg->Draw(screen->window);

	c[0]->Draw(screen->window);
	c[1]->Draw(screen->window);
	c[2]->Draw(screen->window);

	tree->Draw(screen->window);

	bee->Draw(screen->window);

	screen->window->draw(*(score));

	screen->window->display();
}