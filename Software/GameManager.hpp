#pragma once

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "InputManager.hpp"
#include "Player.hpp"

struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
	std::unique_ptr<Player> player1;
	std::unique_ptr<Player> player2;
	bool _gameOver;
	int _turn;
	int _prevCol;
	int numReported{ 0 };
};

typedef std::shared_ptr<GameData> GameDataRef;


class GameManager
{
public:
	GameManager(int width, int height, std::string title);

private:
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;

	GameDataRef _data = std::make_shared<GameData>();
	void Run();
};