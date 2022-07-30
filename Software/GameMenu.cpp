#include <sstream>
#include <iostream>
#include "GameMenuState.hpp"
#include "GameState.hpp"
#include "PlayerUser.hpp"
#include "PlayerRandom.hpp"
#include "PlayerSymmetric.hpp"
#include "PlayerCopy.hpp"
#include "PlayerLeft.hpp"
#include "PlayerRight.hpp"
#include "PlayerNaiveRowEval.hpp"
#include "PlayerMiniMaxRowEval.hpp"
#include "PlayerMiniMaxRowEvalDepth5.hpp"
#include "PlayerMiniMaxRowEvalDepth10.hpp"
#include "PlayerMiniMaxABRowEval.hpp"
#include "PlayerMiniMaxABRowEvalDepth5.hpp"
#include "PlayerMiniMaxABRowEvalDepth10.hpp"

GameMenuState::GameMenuState(GameDataRef data): _data(data)
{

}

void GameMenuState::Init()
{
	//this->_data->assets.LoadTexture("Game Menu Background", "Resourses\\grid.png");
	//_background.setTexture(this -> _data -> assets.GetTexture("Game Menu Background"));
}

void GameMenuState::HandleInput()
{
	sf::Event event;
	sf::Vector2i pos;

	while (this -> _data -> window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		if(sf::Event::MouseButtonPressed == event.type)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				pos = sf::Mouse::getPosition(this->_data->window);
				std::cout << pos.x << ";" << pos.y << std::endl;
			}
		}
	}
}

void GameMenuState::Update(float dt)
{
	if (this->_clock.getElapsedTime().asSeconds() > 1)
	{
		this->_data->player1 = std::make_unique<PlayerNaiveRowEval>(this->_data , PLAYER_ONE_DISC);
		this->_data->player2 = std::make_unique<PlayerUser>(this->_data, PLAYER_TWO_DISC);
		//PlayerUser
		//PlayerRandom PlayerSymmetric PlayerCopy PlayerLeft PlayerRight
		// PlayerNaiveRowEval 
		// PlayerMiniMaxRowEval PlayerMiniMaxRowEvalDepth5	PlayerMiniMaxRowEvalDepth10
		// PlayerMiniMaxABRowEval PlayerMiniMaxABRowEvalDepth5	PlayerMiniMaxABRowEvalDepth10
		// 
		// PlayerNegaMaxRowEval
		this->_data->machine.AddState(StateRef(new GameState_14x12(_data)), true);
	}
}

void GameMenuState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	//this->_data->window.draw(this->_background);
	this->_data->window.display();
}