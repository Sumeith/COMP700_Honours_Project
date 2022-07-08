#include <sstream>
#include <iostream>
#include "GameMenuState.hpp"
#include "GameState.hpp"
#include "PlayerUser.hpp"

GameMenuState::GameMenuState(GameDataRef data): _data(data)
{

}

void GameMenuState::Init()
{
	this->_data->assets.LoadTexture("Game Menu Background", "Resourses\\grid.png");
	_background.setTexture(this -> _data -> assets.GetTexture("Game Menu Background"));
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
		this->_data->player1 = std::make_unique<PlayerUser>(this->_data , PLAYER_ONE_DISC);
		this->_data->player2 = std::make_unique<PlayerUser>(this->_data, PLAYER_TWO_DISC);

		this->_data->machine.AddState(StateRef(new GameState_4x4(_data)), true);
	}
}

void GameMenuState::Draw(float dt)
{
	this->_data->window.clear(sf::Color::Red);
	//this->_data->window.draw(this->_background);
	this->_data->window.display();
}