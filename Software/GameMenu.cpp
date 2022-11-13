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

#include "PlayerMiniMaxABWeight1Eval.hpp"
#include "PlayerMiniMaxABWeight1EvalDepth5.hpp"
#include "PlayerMiniMaxABWeight1EvalDepth10.hpp"

#include "PlayerMiniMaxABWeight2Eval.hpp"
#include "PlayerMiniMaxABWeight2EvalDepth5.hpp"
#include "PlayerMiniMaxABWeight2EvalDepth10.hpp"

#include "PlayerMiniMaxABWeight3Eval.hpp"
#include "PlayerMiniMaxABWeight3EvalDepth5.hpp"
#include "PlayerMiniMaxABWeight3EvalDepth10.hpp"

#include "PlayerMiniMaxABRowWeight1Eval.hpp"
#include "PlayerMiniMaxABRowWeight1EvalDepth5.hpp"
#include "PlayerMiniMaxABRowWeight1EvalDepth10.hpp"

#include "PlayerMiniMaxABRowWeight3Eval.hpp"
#include "PlayerMiniMaxABRowWeight3EvalDepth5.hpp"
#include "PlayerMiniMaxABRowWeight3EvalDepth10.hpp"


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

	}
}

void GameMenuState::Update(float dt)
{

	/*this->_data->player1 = std::make_unique<PlayerMiniMaxRowWeight3EvalDepth5>(this->_data, PLAYER_ONE_DISC);
	this->_data->player2 = std::make_unique<PlayerMiniMaxRowWeight3EvalDepth5>(this->_data, PLAYER_TWO_DISC);

	this->_data->machine.AddState(StateRef(new GameState_4x4(_data)), true);*/
	
	if (this->_data->numReported < 5)
	{
		this->_data->player1 = std::make_unique<PlayerMiniMaxWeight1EvalDepth5>(this->_data, PLAYER_ONE_DISC);
		this->_data->player2 = std::make_unique<PlayerMiniMaxABRowWeight1EvalDepth5>(this->_data, PLAYER_TWO_DISC);
		this->_data->machine.AddState(StateRef(new GameState_4x4(_data)), true);
	}
	else 
	{
		exit(EXIT_SUCCESS);
	}
}

void GameMenuState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	//this->_data->window.draw(this->_background);
	this->_data->window.display();
}