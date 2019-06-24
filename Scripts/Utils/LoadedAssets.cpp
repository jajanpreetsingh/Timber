#include "LoadedAssets.h"
#include "Constants.h"

LoadedAssets::LoadedAssets()
{
	Init();
}

void LoadedAssets::Init()
{
	LoadTexture(TextureType::Bee, Constants::SpritePath + "bee.png");
	LoadTexture(TextureType::Cloud, Constants::SpritePath + "cloud.png");
	LoadTexture(TextureType::Tree, Constants::SpritePath + "tree.png");
	LoadTexture(TextureType::Background, Constants::SpritePath + "background.png");
	LoadTexture(TextureType::Branch, Constants::SpritePath + "branch.png");

	LoadFont(FontType::Komika, Constants::FontPath + "KOMIKAP_.ttf");
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
