#include <sstream>
#include <string>
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
#include "PlayerNaiveWeight1Eval.hpp"
#include "PlayerNaiveWeight2Eval.hpp"
#include "PlayerNaiveWeight3Eval.hpp"
#include "PlayerNaiveRowWeight1Eval.hpp"
#include "PlayerNaiveRowWeight2Eval.hpp"
#include "PlayerNaiveRowWeight3Eval.hpp"
#include "PlayerMiniMaxRowEval.hpp"
#include "PlayerMiniMaxRowEvalDepth5.hpp"
#include "PlayerMiniMaxRowEvalDepth10.hpp"
#include "PlayerMiniMaxWeight1Eval.hpp"
#include "PlayerMiniMaxWeight1EvalDepth5.hpp"
#include "PlayerMiniMaxWeight1EvalDepth10.hpp"
#include "PlayerMiniMaxWeight2Eval.hpp"
#include "PlayerMiniMaxWeight2EvalDepth5.hpp"
#include "PlayerMiniMaxWeight2EvalDepth10.hpp"
#include "PlayerMiniMaxRowWeight1Eval.hpp"
#include "PlayerMiniMaxRowWeight1EvalDepth5.hpp"
#include "PlayerMiniMaxRowWeight1EvalDepth10.hpp"

#include "PlayerMiniMaxRowWeight2Eval.hpp"
#include "PlayerMiniMaxRowWeight2EvalDepth5.hpp"
#include "PlayerMiniMaxRowWeight2EvalDepth10.hpp"


#include "PlayerMiniMaxABRowWeight2Eval.hpp"
#include "PlayerMiniMaxABRowWeight2EvalDepth5.hpp"
#include "PlayerMiniMaxABRowWeight2EvalDepth10.hpp"

#include "PlayerMiniMaxRowWeight3Eval.hpp"
#include "PlayerMiniMaxRowWeight3EvalDepth5.hpp"
#include "PlayerMiniMaxRowWeight3EvalDepth10.hpp"



#include "PlayerMiniMaxWeight3Eval.hpp"
#include "PlayerMiniMaxWeight3EvalDepth5.hpp"
#include "PlayerMiniMaxWeight3EvalDepth10.hpp"

#include "PlayerMiniMaxABRowEval.hpp"
#include "PlayerMiniMaxABRowEvalDepth5.hpp"
#include "PlayerMiniMaxABRowEvalDepth10.hpp"

#include "PlayerMiniMaxABRowWeight1Eval.hpp"
#include "PlayerMiniMaxABRowWeight1EvalDepth5.hpp"
#include "PlayerMiniMaxABRowWeight1EvalDepth10.hpp"

#include "PlayerNegaMaxRowEval.hpp"
#include "PlayerNegaMaxABRowEval.hpp"

GameMenuState::GameMenuState(GameDataRef data): _data(data)
{

}

void GameMenuState::Init()
{
	playerSet = false;
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

		/*if(sf::Event::MouseButtonPressed == event.type)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				pos = sf::Mouse::getPosition(this->_data->window);
				std::cout << pos.x << ";" << pos.y << std::endl;
			}
		}*/
	}
}

void GameMenuState::Update(float dt)
{

	this->_data->player1 = std::make_unique<PlayerMiniMaxABRowWeight2EvalDepth10>(this->_data, PLAYER_ONE_DISC);
	this->_data->player2 = std::make_unique<PlayerUser>(this->_data, PLAYER_TWO_DISC);

	this->_data->machine.AddState(StateRef(new GameState_4x4(_data)), true);
	//for (int i = 0; i < 2; i++)
	//{


	//	if (!playerSet)
	//	{
	//		int player1_choice = 0;
	//		int player2_choice = 0;

	//		std::cout << "Welcome to Connect 4" << std::endl;
	//		std::cout << "Please select 1 of the following players: " << std::endl;
	//		std::cout << "[1] Player User" << std::endl;
	//		std::cin >> player1_choice;
	//		std::cin >> player2_choice;
	//		playerSet = true;
	//		/*this->_data->player1 = std::make_unique<PlayerUser>(this->_data , PLAYER_ONE_DISC);
	//		this->_data->player2 = std::make_unique<PlayerUser>(this->_data, PLAYER_TWO_DISC);*/

	//		//PlayerUser
	//		//PlayerRandom PlayerSymmetric PlayerCopy PlayerLeft PlayerRight
	//		// PlayerNaiveRowEval 
	//		// PlayerMiniMaxRowEval PlayerMiniMaxRowEvalDepth5	PlayerMiniMaxRowEvalDepth10
	//		// PlayerMiniMaxABRowEval PlayerMiniMaxABRowEvalDepth5	PlayerMiniMaxABRowEvalDepth10
	//		// 
	//		// PlayerNegaMaxRowEval

	//		//PlayerNegaMaxABRowEval

	//		setPlayer(1, player1_choice);
	//		setPlayer(2, player2_choice);
	//		this->_data->machine.AddState(StateRef(new GameState_7x6(_data)), true);

	//	}
	//}
}

void GameMenuState::setPlayer(int playerNum, int choice)
{
	switch (playerNum)
	{
	case 1:
		switch (choice)
		{
		case 1:
			this->_data->player1 = std::make_unique<PlayerUser>(this->_data, PLAYER_ONE_DISC);
		default:
			break;
		}
		break;
	case 2:
		switch (choice)
		{
		case 1:
			this->_data->player2 = std::make_unique<PlayerUser>(this->_data, PLAYER_TWO_DISC);
		default:
			break;
		}
	default:
		break;
	}
}

void GameMenuState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	//this->_data->window.draw(this->_background);
	this->_data->window.display();
}