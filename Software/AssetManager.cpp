#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
	sf::Texture texture;

	if (texture.loadFromFile(fileName))
	{
		this->_textureMap[name] = texture;
	}
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
	return this->_textureMap.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
	sf::Font font;

	if (font.loadFromFile(fileName))
	{
		this->_fontMap[name] = font;
	}
}

sf::Font& AssetManager::GetFont(std::string name)
{
	return this->_fontMap.at(name);
}

void AssetManager::LoadSound(std::string name, std::string fileName)
{
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	if (soundBuffer.loadFromFile(fileName))
	{
		sound.setBuffer(soundBuffer);
		this->_soundMap[name] = sound;
	}
}

sf::Sound& AssetManager::GetSound(std::string name)
{
	return this->_soundMap.at(name);
}