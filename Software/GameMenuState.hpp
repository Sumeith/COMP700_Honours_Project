#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameManager.hpp"

class GameMenuState : public State
{
public:
	GameMenuState(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

	void setPlayer(int player, int choice);
private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;

	bool playerSet;
};