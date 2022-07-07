#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameMenuState.hpp"
#include <iostream>
#include <windows.h>

GameState_4x4::GameState_4x4(GameDataRef data) : _data(data)
{

}

void GameState_4x4::Init()
{
	_turn = PLAYER_ONE_DISC;
	_gameOver = false;
	this->_data->assets.LoadTexture("Game BOARD", GAME_BOARD_PATH);

	this->_data->assets.LoadTexture("Player One Disc", PLAYER_ONE_DISC_PATH);
	this->_data->assets.LoadTexture("Player Two Disc", PLAYER_TWO_DISC_PATH);
	this->_data->assets.LoadTexture("Empty Disc", EMPTY_DISC_PATH);
	this->_data->assets.LoadTexture("Game Board", GAME_BOARD_PATH);

	this->_data->window.create(sf::VideoMode(SCREEN_WIDTH_4x4, SCREEN_HEIGHT_4x4), TITLE_4x4, sf::Style::Close | sf::Style::Titlebar);

	this->_background.setTexture(this->_data->assets.GetTexture("Game BOARD"));

	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			_board._grid[x][y] = EMPTY_DISC;
		}
	}


	InitGridPieces();
}

void GameState_4x4::InitGridPieces()
{
	sf::Vector2u tempDiscSize = this->_data->assets.GetTexture("Empty Disc").getSize();

	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			_boardPieces[x][y].setTexture(this->_data->assets.GetTexture("Empty Disc"));
			_boardPieces[x][y].setPosition(tempDiscSize.y * y, tempDiscSize.x * x);
		}
	}
}

void GameState_4x4::dropDisc()
{
	sf::Vector2i mousePoint = this->_data->input.GetMousePosition(this->_data->window);
	int column = 0;
	int tempWidth = this->_data->assets.GetTexture("Empty Disc").getSize().x;
	for (int colNum = 0; colNum < _width; colNum++)
	{
		if ((mousePoint.x >= colNum * tempWidth) && (mousePoint.x < (colNum + 1) * (tempWidth))) {
			column = colNum;
		}
	}

	if (_board._grid[0][column] != EMPTY_DISC)
	{
		std::cout << "Column " << column + 1 << " is Full" << std::endl;
	}
	else if (0 <= column && column <= _width)
	{
		for (int row = _height - 1; row >= 0; row--)
		{
			if (_board._grid[row][column] == EMPTY_DISC)
			{
				_board._grid[row][column] = _turn;

				if (_turn == PLAYER_ONE_DISC)
				{
					_boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player One Disc"));
					_turn = PLAYER_TWO_DISC;
				}
				else if (_turn == PLAYER_TWO_DISC)
				{
					_boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
					_turn = PLAYER_ONE_DISC;
				}
				else
				{
					std::cout << "Invalid Disc" << std::endl;
				}
				break;
			}
		}
	}
	else
	{
		std::cout << "Column (" << column + 1 << ") Invalid" << std::endl;
	}
}

std::string GameState_4x4::Colour(int colour = 7, std::string message = " ")
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	return message;
}

void GameState_4x4::printBoard()
{
	for (int i = 1; i <= _width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < _height; x++)
	{

		for (int y = 0; y < _width; y++)
		{
			if (_board._grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (_board._grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
}

void GameState_4x4::checkWinner()
{
	//check Horizontally
	for (int col = 0; col < (_width - 3); col++)
	{
		for (int row = 0; row < _height; row++)
		{
			if (_board._grid[row][col] == PLAYER_ONE_DISC &&
				_board._grid[row][col + 1] == PLAYER_ONE_DISC &&
				_board._grid[row][col + 2] == PLAYER_ONE_DISC &&
				_board._grid[row][col + 3] == PLAYER_ONE_DISC)
			{
				_gameOver = true;
				std::cout << "Red Player Wins" << std::endl;
				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 3].setScale(1.1f, 1.1f);
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;
				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row][col + 3].setScale(1.1f, 1.1f);
				return;
			}
		}
	}

	//check Vertically
	for (int col = 0; col < _width; col++)
	{
		for (int row = 0; row < (_height - 3); row++)
		{
			if (_board._grid[row][col] == PLAYER_ONE_DISC &&
				_board._grid[row + 1][col] == PLAYER_ONE_DISC &&
				_board._grid[row + 2][col] == PLAYER_ONE_DISC &&
				_board._grid[row + 3][col] == PLAYER_ONE_DISC)
			{
				_gameOver = true;
				std::cout << "Red Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 1][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 2][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 3][col].setScale(1.1f, 1.1f);
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 1][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 2][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 3][col] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 1][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 2][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 3][col].setScale(1.1f, 1.1f);
				return;
			}
		}
	}

	//check (positive) Diagonal 
	for (int col = 0; col < (_width - 3); col++)
	{
		for (int row = 0; row < (_height - 3); row++)
		{
			if (_board._grid[row][col] == PLAYER_ONE_DISC &&
				_board._grid[row + 1][col + 1] == PLAYER_ONE_DISC &&
				_board._grid[row + 2][col + 2] == PLAYER_ONE_DISC &&
				_board._grid[row + 3][col + 3] == PLAYER_ONE_DISC)
			{
				_gameOver = true;
				std::cout << "Red Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 1][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row + 2][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row + 3][col + 3].setScale(1.1f, 1.1f);
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row + 3][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row + 1][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row + 2][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row + 3][col + 3].setScale(1.1f, 1.1f);
				return;
			}
		}
	}

	//check (negative) Diagonal 
	for (int col = 0; col < (_width - 3); col++)
	{
		for (int row = 3; row < _height; row++)
		{
			if (_board._grid[row][col] == PLAYER_ONE_DISC &&
				_board._grid[row - 1][col + 1] == PLAYER_ONE_DISC &&
				_board._grid[row - 2][col + 2] == PLAYER_ONE_DISC &&
				_board._grid[row - 3][col + 3] == PLAYER_ONE_DISC)
			{
				_gameOver = true;
				std::cout << "Red Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row - 1][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row - 2][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row - 3][col + 3].setScale(1.1f, 1.1f);
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row - 3][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;

				_boardPieces[row][col].setScale(1.1f, 1.1f);
				_boardPieces[row - 1][col + 1].setScale(1.1f, 1.1f);
				_boardPieces[row - 2][col + 2].setScale(1.1f, 1.1f);
				_boardPieces[row - 3][col + 3].setScale(1.1f, 1.1f);
				return;
			}
		}
	}
}

/*
* The evaluation
*/
int GameState_4x4::gameEvaluation()
{
	return 0;
}

void GameState_4x4::HandleInput()
{
	sf::Event event;
	sf::Vector2i pos;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		if (sf::Event::MouseButtonPressed == event.type && !_gameOver)
		{
			dropDisc();
			printBoard();
			checkWinner();
		}

		if (sf::Event::KeyPressed == event.type)
		{
			if (sf::Keyboard::Q == event.key.code)
			{
				this->_data->window.close();
			}

			if (sf::Keyboard::N == event.key.code)
			{
				this->_data->machine.AddState(StateRef(new GameMenuState(_data)), true);
			}
		}
	}
}

void GameState_4x4::Update(float dt)
{
	if (_gameOver)
	{
		if (this->_clock.getElapsedTime().asSeconds() > TRANSITION_TIME)
		{
			this->_data->machine.AddState(StateRef(new GameMenuState(_data)), true);
		}
	}
}

void GameState_4x4::Draw(float dt)
{
	this->_data->window.clear(sf::Color::White);
	//this->_data->window.draw(this->_background);

	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			this->_data->window.draw(this->_boardPieces[x][y]);
		}
	}
	this->_data->window.display();
}