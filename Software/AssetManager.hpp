#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager
{
public:
	AssetManager() {}
	~AssetManager() {}

	void LoadTexture(std::string name, std::string fileName);
	sf::Texture& GetTexture(std::string name);

	void LoadFont(std::string name, std::string fileName);
	sf::Font& GetFont(std::string name);

	void LoadSound(std::string name, std::string fileName);
	sf::Sound& GetSound(std::string name);;

private:
	std::map<std::string, sf::Texture> _textureMap;
	std::map<std::string, sf::Font> _fontMap;
	std::map<std::string, sf::Sound> _soundMap;
};