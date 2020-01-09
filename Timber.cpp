#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "JungleView.h"
#include "Utils.h"
#include "LoadedAssets.h"
#include "Screen.h"

using namespace sf;

void ProcessInput();
void SetupScreen();

bool paused = false;

Screen* screen = NULL;

std::map<TextureType, sf::Texture> LoadedAssets::Textures;

std::map<FontType, sf::Font> LoadedAssets::Fonts;

std::map<SoundType, sf::SoundBuffer> LoadedAssets::Sounds;

LoadedAssets* assets;

JungleView* level;

int main()
{
	// Create a video mode object
	SetupScreen();

	srand(time(0));

	assets = new LoadedAssets();

	FloatRect* rec = new sf::FloatRect(0, 0, screen->WIDTH, screen->HEIGHT);

	level = new JungleView(screen->window, rec);

	Clock clock;

	while (screen->window->isOpen())
	{
		ProcessInput();

		if (paused)
		{
			continue;
		}
		
		level->Update(clock);
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
		exit(0);
	}

	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		paused = !paused;
	}
}