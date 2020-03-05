#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Screen.h>
#include <LoadedAssets.h>
#include <JungleView.h>

class Engine
{
private:

	Screen* screen = NULL;

	LoadedAssets* assets;

	JungleView* level;

	bool gamePaused;

	float totalGameTimeInSec;
	
	void ProcessInput();

	void Update(sf::Clock clock);

	void Draw();

public:

	Engine();

	void Run();

	float GetTotalTime() const;
};

