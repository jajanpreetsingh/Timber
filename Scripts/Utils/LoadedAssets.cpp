#include "LoadedAssets.h"
#include "Constants.h"

LoadedAssets::LoadedAssets()
{
	Init();
}

void LoadedAssets::Init()
{
	LoadTexture(TextureType::Bee, "bee.png");
	LoadTexture(TextureType::Cloud, "cloud.png");
	LoadTexture(TextureType::Cloud2, "cloud2.png");
	//LoadTexture(TextureType::Tree, "tree.png");
	LoadTexture(TextureType::Background, "background.png");
	//LoadTexture(TextureType::Branch, "branch.png");
	LoadTexture(TextureType::All, "allImages.png");

	LoadFont(FontType::Komika, "KOMIKAP_.ttf");

	LoadSound(SoundType::Chop, "chop.wav");
}

void LoadedAssets::LoadFont(FontType key, std::string filename)
{
	sf::Font f;
	if (f.loadFromFile(Constants::FontPath + filename))
	{
		Fonts[key] = f;
	}
}

void LoadedAssets::LoadTexture(TextureType key, std::string filename)
{
	sf::Texture t;
	t.loadFromFile(Constants::SpritePath + filename);

	Textures[key] = t;
}

void LoadedAssets::LoadSound(SoundType key, std::string filename)
{
	sf::SoundBuffer s;
	s.loadFromFile(Constants::AudioPath + filename);

	Sounds[key] = s;
}

sf::Texture* LoadedAssets::GetTexture(TextureType key)
{
	return &Textures[key];
}

sf::Font* LoadedAssets::GetFont(FontType key)
{
	return &Fonts[key];
}

sf::SoundBuffer* LoadedAssets::GetSoundBuffer(SoundType key)
{
	return &Sounds[key];
}

std::vector<sf::Texture> LoadedAssets::GetTextures(std::vector < std::string> fileNames, std::string customePathAppend)
{
	std::vector<sf::Texture> texs;

	for (int i = 0; i < fileNames.size(); i++)
	{
		sf::Texture t;
		t.loadFromFile(Constants::SpritePath + customePathAppend + fileNames[i]);
		texs.push_back(t);
	}

	return texs;
}

LoadedAssets::~LoadedAssets()
{
}
