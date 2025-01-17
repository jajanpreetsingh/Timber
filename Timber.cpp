#pragma once

#include <iostream>
#include <Engine.h>

std::map<TextureType, sf::Texture> LoadedAssets::Textures;

std::map<FontType, sf::Font> LoadedAssets::Fonts;

std::map<SoundType, sf::SoundBuffer> LoadedAssets::Sounds;

std::map<ShaderType, sf::Shader*> Shaders;

int main()
{
	(new Engine())->Run();

	return 0;
}