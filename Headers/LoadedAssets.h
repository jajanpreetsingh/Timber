#include <string>
#include <SFML/Graphics.hpp>
#include <cstdlib>

#pragma once

enum class TextureType
{
	Cloud,
	Bee,
	Tree,
	Background,
	Branch
};

enum class FontType
{
	Komika
};

class LoadedAssets
{

public:

	static std::map<TextureType, sf::Texture> Textures;

	static std::map<FontType, sf::Font> Fonts;

	LoadedAssets();

	void Init();

	void LoadFont(FontType key, std::string filename);

	void LoadTexture(TextureType key, std::string filename);

	static sf::Texture GetTexture(TextureType key);

	static sf::Font GetFont(FontType key);

	~LoadedAssets();
};

