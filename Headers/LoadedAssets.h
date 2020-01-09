#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cstdlib>

#pragma once

enum class TextureType
{
	Cloud,
	Cloud2,
	Bee,
	Tree,
	Background,
	Branch
};

enum class FontType
{
	Komika
};

enum class SoundType
{
	Chop
};

class LoadedAssets
{
private:

	static std::map<TextureType, sf::Texture> Textures;

	static std::map<FontType, sf::Font> Fonts;

	static std::map<SoundType, sf::SoundBuffer> Sounds;

public:

	LoadedAssets();

	void Init();

	void LoadFont(FontType key, std::string filename);

	void LoadTexture(TextureType key, std::string filename);

	void LoadSound(SoundType key, std::string filename);

	static sf::Texture* GetTexture(TextureType key);

	static sf::Font* GetFont(FontType key);

	static sf::SoundBuffer* GetSoundBuffer(SoundType key);

	static std::vector<sf::Texture> GetTextures(std::vector<std::string> fileNames, std::string customePathAppend = std::string(""));

	~LoadedAssets();
};
