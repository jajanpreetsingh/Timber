#include "LoadedAssets.h"

LoadedAssets::LoadedAssets()
{
	Init();
}

void LoadedAssets::Init()
{
	LoadTexture(TextureType::Bee, "graphics/bee.png");
	LoadTexture(TextureType::Cloud, "graphics/cloud.png");
	LoadTexture(TextureType::Tree, "graphics/tree.png");
	LoadTexture(TextureType::Background, "graphics/background.png");

	LoadFont(FontType::Komika, "fonts/KOMIKAP_.ttf");
}

void LoadedAssets::LoadFont(FontType key, std::string filename)
{
	sf::Font f;
	f.loadFromFile(filename);

	Fonts[key] = f;
}

void LoadedAssets::LoadTexture(TextureType key, std::string filename)
{
	sf::Texture t;
	t.loadFromFile(filename);

	Textures[key] = t;
}

sf::Texture LoadedAssets::GetTexture(TextureType key)
{
	return Textures[key];
}

sf::Font LoadedAssets::GetFont(FontType key)
{
	return Fonts[key];
}

LoadedAssets::~LoadedAssets()
{
}
