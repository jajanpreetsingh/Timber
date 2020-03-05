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
	LoadSound(SoundType::Bee, "bee.wav");

	//LoadShader(ShaderType::Ripple, "vertShader.vert", "rippleShader.frag");
}

void LoadedAssets::LoadFont(FontType key, std::string filename)
{
	sf::Font f;
	if (f.loadFromFile(Constants::PATH_FONT + filename))
	{
		Fonts[key] = f;
	}
}

void LoadedAssets::LoadTexture(TextureType key, std::string filename)
{
	sf::Texture t;
	t.loadFromFile(Constants::PATH_SPRITE + filename);

	Textures[key] = t;
}

void LoadedAssets::LoadSound(SoundType key, std::string filename)
{
	sf::SoundBuffer s;
	s.loadFromFile(Constants::PATH_AUDIO + filename);

	Sounds[key] = s;
}

//void LoadedAssets::LoadShader(ShaderType key, std::string vertFilename, std::string fragFilename)
//{
//	sf::Shader s;
//	s.loadFromFile(vertFilename, fragFilename);
//
//	Shaders[key] = &s;
//}

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

//sf::Shader* LoadedAssets::GetShader(ShaderType key)
//{
//	return Shaders[key];
//}

std::vector<sf::Texture> LoadedAssets::GetTextures(std::vector < std::string> fileNames, std::string customePathAppend)
{
	std::vector<sf::Texture> texs;

	for (int i = 0; i < fileNames.size(); i++)
	{
		sf::Texture t;
		t.loadFromFile(Constants::PATH_SPRITE + customePathAppend + fileNames[i]);
		texs.push_back(t);
	}

	return texs;
}

LoadedAssets::~LoadedAssets()
{
}
