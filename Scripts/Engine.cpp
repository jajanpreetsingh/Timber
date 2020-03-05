#include <Engine.h>

void Engine::ProcessInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		screen->window->close();
		exit(0);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		gamePaused = !gamePaused;
	}
}

void Engine::Update(sf::Clock clock)
{
	float dtInSeconds = clock.restart().asSeconds();

	level->bgShader.setUniform("uTime", GetTotalTime());

	ProcessInput();

	if (gamePaused)
	{
		return;
	}
	
	totalGameTimeInSec += dtInSeconds;
	level->Update(dtInSeconds);
}

void Engine::Draw()
{
}

Engine::Engine()
{
	gamePaused = false;

	totalGameTimeInSec = 0;

	screen = new Screen();

	assets = new LoadedAssets();

	sf::FloatRect* rec = new sf::FloatRect(0, 0, (screen->WIDTH) / 8, (screen->HEIGHT) / 8);

	level = new JungleView(screen->window, *rec);
}

void Engine::Run()
{
	srand(time(0));

	Clock clock;

	while (screen->window->isOpen())
	{
		Update(clock);
	}
}

float Engine::GetTotalTime() const
{
	return totalGameTimeInSec;
}


