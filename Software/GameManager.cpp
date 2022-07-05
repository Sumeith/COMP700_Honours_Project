#include "GameManager.hpp"
#include "GameMenuState.hpp"
GameManager::GameManager(int width, int height, std::string title)
{
	_data -> window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
	_data->machine.AddState(StateRef(new GameMenuState(this -> _data)));
	this->Run();
}

void GameManager::Run()
{
	float newTime, frameTime, interpolation;

	float currentTime = this->_clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (this->_data->window.isOpen()) 
	{
		this->_data->machine.StateTransition();
		newTime = this->_clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
		{
			frameTime = 0.25;
		}

		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->_data->machine.GetActiveState()->HandleInput();
			this->_data->machine.GetActiveState()->Update(dt);
			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->_data->machine.GetActiveState()->Draw(interpolation);
	}
}
