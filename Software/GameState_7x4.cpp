//#include <sstream>
#include <iostream>
#include "GameState.hpp"
#include "DEFINITIONS.hpp"
#include "GameMenuState.hpp"
#include <iostream>
#include <windows.h>
#include "PlayerUser.hpp"

GameState_7x4::GameState_7x4(GameDataRef data) : _data(data)
{
	eval = 0;

}

void GameState_7x4::Init()
{
	this->_data->_turn = PLAYER_ONE;
	this->_data->_gameOver = false;
	this->_data->_prevCol = -1;

	//this->_data->assets.LoadTexture("Game BOARD", GAME_BOARD_PATH);

	this->_data->assets.LoadTexture("Player One Disc", PLAYER_ONE_DISC_PATH);
	this->_data->assets.LoadTexture("Player Two Disc", PLAYER_TWO_DISC_PATH);
	this->_data->assets.LoadTexture("Player One Win Disc", PLAYER_ONE_WIN_DISC_PATH);
	this->_data->assets.LoadTexture("Player Two Win Disc", PLAYER_TWO_WIN_DISC_PATH);

	this->_data->assets.LoadTexture("Empty Disc", EMPTY_DISC_PATH);
	//this->_data->assets.LoadTexture("Game Board", GAME_BOARD_PATH);

	this->_data->window.create(sf::VideoMode(SCREEN_WIDTH_7x4, SCREEN_HEIGHT_7x4), TITLE_7x4, sf::Style::Close | sf::Style::Titlebar);

	//this->_background.setTexture(this->_data->assets.GetTexture("Game BOARD"));

	for (int x = 0; x < _height; x++)
	{
		for (int y = 0; y < _width; y++)
		{
			_board._grid[x][y] = EMPTY_DISC;
		}
	}


	InitGridPieces();
}

void GameState_7x4::InitGridPieces()
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

void GameState_7x4::checkWinner()
{
	//if game is a draw
	if (numDiscs == totalDiscs)
	{
		this->_data->_gameOver = true;
		this->_data->player1->result = 0;
		this->_data->player2->result = 0;
		return;
	}

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
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row][col + 1].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row][col + 2].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row][col + 3].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = 1;
				this->_data->player2->result = -1;
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row][col + 1].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row][col + 2].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row][col + 3].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = -1;
				this->_data->player2->result = 1;
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
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 1][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 2][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 3][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = 1;
				this->_data->player2->result = -1;
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 1][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 2][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 3][col] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 1][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 2][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 3][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = -1;
				this->_data->player2->result = 1;
				return;
			}
		}
	}

	//check (positive) Diagonal 
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
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row - 1][col + 1].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row - 2][col + 2].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row - 3][col + 3].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = 1;
				this->_data->player2->result = -1;
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row - 3][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row - 1][col + 1].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row - 2][col + 2].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row - 3][col + 3].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = -1;
				this->_data->player2->result = 1;
				return;
			}
		}
	}

	//check (negative) Diagonal 
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
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 1][col + 1].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 2][col + 2].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				_boardPieces[row + 3][col + 3].setTexture(this->_data->assets.GetTexture("Player One Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = 1;
				this->_data->player2->result = -1;
				return;
			}

			if (_board._grid[row][col] == PLAYER_TWO_DISC &&
				_board._grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
				_board._grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
				_board._grid[row + 3][col + 3] == PLAYER_TWO_DISC)
			{
				_gameOver = true;
				std::cout << "Blue Player Wins" << std::endl;
				_boardPieces[row][col].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 1][col + 1].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 2][col + 2].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				_boardPieces[row + 3][col + 3].setTexture(this->_data->assets.GetTexture("Player Two Win Disc"));
				this->_data->_gameOver = true;
				this->_data->player1->result = -1;
				this->_data->player2->result = 1;
				return;
			}
		}
	}
}

void GameState_7x4::HandleInput()
{
	sf::Event event;
	sf::Vector2i pos;

	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}

		if (sf::Event::MouseButtonPressed == event.type && !this->_data->_gameOver)
		{
			if (this->_data->_turn == PLAYER_ONE && typeid(*this->_data->player1) == typeid(PlayerUser))
			{
				this->_data->player1->nextMove(&_board, _boardPieces);
				eval = this->_data->player1->getEvaluation();
				this->_data->_turn = PLAYER_TWO;
				numDiscs++;
			}
			else if (this->_data->_turn == PLAYER_TWO && typeid(*this->_data->player2) == typeid(PlayerUser))
			{
				this->_data->player2->nextMove(&_board, _boardPieces);
				eval = this->_data->player2->getEvaluation();
				this->_data->_turn = PLAYER_ONE;
				numDiscs++;
			}
			//dropDisc();
			printBoard(&_board);
			checkWinner();
			//std::cout << "eval: " << gameEvaluation() << std::endl;
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

void GameState_7x4::Update(float dt)
{
	if (!this->_data->_gameOver &&
		(!(typeid(*this->_data->player1) == typeid(PlayerUser)) ||
			!(typeid(*this->_data->player2) == typeid(PlayerUser))))
	{
		if (this->_data->_turn == PLAYER_ONE && !(typeid(*this->_data->player1) == typeid(PlayerUser)))
		{
			this->_data->player1->nextMove(&_board, _boardPieces);
			eval = this->_data->player1->getEvaluation();
			numDiscs++;
			printBoard(&_board);
			checkWinner();

			this->_data->_turn = PLAYER_TWO;
		}
		else if (this->_data->_turn == PLAYER_TWO && !(typeid(*this->_data->player2) == typeid(PlayerUser)))
		{
			this->_data->player2->nextMove(&_board, _boardPieces);
			eval = this->_data->player2->getEvaluation();
			numDiscs++;
			printBoard(&_board);
			checkWinner();
			this->_data->_turn = PLAYER_ONE;
		}

		else
		{
			if (this->_clock.getElapsedTime().asSeconds() > TRANSITION_TIME)
			{
				if (!reported)
				{
					this->_data->numReported++;
					//if statement ensures that draws are recorded properly
					if (numDiscs == totalDiscs)
					{
						this->_data->player1->result = 0;
						this->_data->player2->result = 0;
					}
					std::string fileName1 = "Board_7x4-"
						+ this->_data->player1->playerName
						+ "vs"
						+ this->_data->player2->playerName
						+ "-"
						+ this->_data->player1->playerName
						+ "1-.csv";

					std::ofstream player1File;
					player1File.open(fileName1.c_str(),
						std::ofstream::out | std::ios_base::app);

					player1File << this->_data->player1->result
						<< ","
						<< this->_data->player1->firstColumn
						<< ","
						<< this->_data->player1->getMaxTime()
						<< ","
						<< this->_data->player1->getMaxRowEval()
						<< ","
						<< this->_data->player1->getMaxWeight1Eval()
						<< ","
						<< this->_data->player1->getMaxWeight2Eval()
						<< ","
						<< this->_data->player1->getMaxWeight3Eval()
						<< ","
						<< this->_data->player1->getMaxRowWeight1Eval()
						<< ","
						<< this->_data->player1->getMaxRowWeight2Eval()
						<< ","
						<< this->_data->player1->getMaxRowWeight3Eval()
						<< ","
						<< this->_data->player1->getMinTime()
						<< ","
						<< this->_data->player1->getMinRowEval()
						<< ","
						<< this->_data->player1->getMinWeight1Eval()
						<< ","
						<< this->_data->player1->getMinWeight2Eval()
						<< ","
						<< this->_data->player1->getMinWeight3Eval()
						<< ","
						<< this->_data->player1->getMinRowWeight1Eval()
						<< ","
						<< this->_data->player1->getMinRowWeight2Eval()
						<< ","
						<< this->_data->player1->getMinRowWeight3Eval()
						<< ","
						<< this->_data->player1->getAverageTime()
						<< ","
						<< this->_data->player1->getAverageRowEval()
						<< ","
						<< this->_data->player1->getAverageWeight1Eval()
						<< ","
						<< this->_data->player1->getAverageWeight2Eval()
						<< ","
						<< this->_data->player1->getAverageWeight3Eval()
						<< ","
						<< this->_data->player1->getAverageRowWeight1Eval()
						<< ","
						<< this->_data->player1->getAverageRowWeight2Eval()
						<< ","
						<< this->_data->player1->getAverageRowWeight3Eval()
						<< ","
						<< this->_data->player1->getMaxRowEvalDiff()
						<< ","
						<< this->_data->player1->getMaxWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getMaxWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getMaxWeight3EvalDiff()
						<< ","
						<< this->_data->player1->getMaxRowWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getMaxRowWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getMaxRowWeight3EvalDiff()
						<< ","
						<< this->_data->player1->getMinRowEvalDiff()
						<< ","
						<< this->_data->player1->getMinWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getMinWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getMinWeight3EvalDiff()
						<< ","
						<< this->_data->player1->getMinRowWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getMinRowWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getMinRowWeight3EvalDiff()
						<< ","
						<< this->_data->player1->getAverageRowEvalDiff()
						<< ","
						<< this->_data->player1->getAverageWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getAverageWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getAverageWeight3EvalDiff()
						<< ","
						<< this->_data->player1->getAverageRowWeight1EvalDiff()
						<< ","
						<< this->_data->player1->getAverageRowWeight2EvalDiff()
						<< ","
						<< this->_data->player1->getAverageRowWeight3EvalDiff()
						<< std::endl;
					player1File.close();

					std::ofstream player2File;
					std::string fileName2 = "Board_7x4-"
						+ this->_data->player1->playerName
						+ "vs"
						+ this->_data->player2->playerName
						+ "-"
						+ this->_data->player2->playerName
						+ "2-.csv";
					player2File.open(fileName2.c_str(),
						std::ofstream::out | std::ios_base::app);

					player2File << this->_data->player2->result
						<< ","
						<< this->_data->player2->firstColumn
						<< ","
						<< this->_data->player2->getMaxTime()
						<< ","
						<< this->_data->player2->getMaxRowEval()
						<< ","
						<< this->_data->player2->getMaxWeight1Eval()
						<< ","
						<< this->_data->player2->getMaxWeight2Eval()
						<< ","
						<< this->_data->player2->getMaxWeight3Eval()
						<< ","
						<< this->_data->player2->getMaxRowWeight1Eval()
						<< ","
						<< this->_data->player2->getMaxRowWeight2Eval()
						<< ","
						<< this->_data->player2->getMaxRowWeight3Eval()
						<< ","
						<< this->_data->player2->getMinTime()
						<< ","
						<< this->_data->player2->getMinRowEval()
						<< ","
						<< this->_data->player2->getMinWeight1Eval()
						<< ","
						<< this->_data->player2->getMinWeight2Eval()
						<< ","
						<< this->_data->player2->getMinWeight3Eval()
						<< ","
						<< this->_data->player2->getMinRowWeight1Eval()
						<< ","
						<< this->_data->player2->getMinRowWeight2Eval()
						<< ","
						<< this->_data->player2->getMinRowWeight3Eval()
						<< ","
						<< this->_data->player2->getAverageTime()
						<< ","
						<< this->_data->player2->getAverageRowEval()
						<< ","
						<< this->_data->player2->getAverageWeight1Eval()
						<< ","
						<< this->_data->player2->getAverageWeight2Eval()
						<< ","
						<< this->_data->player2->getAverageWeight3Eval()
						<< ","
						<< this->_data->player2->getAverageRowWeight1Eval()
						<< ","
						<< this->_data->player2->getAverageRowWeight2Eval()
						<< ","
						<< this->_data->player2->getAverageRowWeight3Eval()
						<< ","
						<< this->_data->player2->getMaxRowEvalDiff()
						<< ","
						<< this->_data->player2->getMaxWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getMaxWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getMaxWeight3EvalDiff()
						<< ","
						<< this->_data->player2->getMaxRowWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getMaxRowWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getMaxRowWeight3EvalDiff()
						<< ","
						<< this->_data->player2->getMinRowEvalDiff()
						<< ","
						<< this->_data->player2->getMinWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getMinWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getMinWeight3EvalDiff()
						<< ","
						<< this->_data->player2->getMinRowWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getMinRowWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getMinRowWeight3EvalDiff()
						<< ","
						<< this->_data->player2->getAverageRowEvalDiff()
						<< ","
						<< this->_data->player2->getAverageWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getAverageWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getAverageWeight3EvalDiff()
						<< ","
						<< this->_data->player2->getAverageRowWeight1EvalDiff()
						<< ","
						<< this->_data->player2->getAverageRowWeight2EvalDiff()
						<< ","
						<< this->_data->player2->getAverageRowWeight3EvalDiff()
						<< std::endl;
					player2File.close();

					reported = true;

				}
				this->_data->machine.AddState(StateRef(new GameMenuState(_data)), true);
			}
		}
	}

	if (this->_data->_gameOver)
	{
		if (this->_clock.getElapsedTime().asSeconds() > TRANSITION_TIME)
		{
			if (!reported)
			{
				this->_data->numReported++;
				//if statement ensures that draws are recorded properly
				if (numDiscs == totalDiscs)
				{
					this->_data->player1->result = 0;
					this->_data->player2->result = 0;
				}
				std::string fileName1 = "Board_7x4-"
					+ this->_data->player1->playerName
					+ "vs"
					+ this->_data->player2->playerName
					+ "-"
					+ this->_data->player1->playerName
					+ "1-.csv";

				std::ofstream player1File;
				player1File.open(fileName1.c_str(),
					std::ofstream::out | std::ios_base::app);

				player1File << this->_data->player1->result
					<< ","
					<< this->_data->player1->firstColumn
					<< ","
					<< this->_data->player1->getMaxTime()
					<< ","
					<< this->_data->player1->getMaxRowEval()
					<< ","
					<< this->_data->player1->getMaxWeight1Eval()
					<< ","
					<< this->_data->player1->getMaxWeight2Eval()
					<< ","
					<< this->_data->player1->getMaxWeight3Eval()
					<< ","
					<< this->_data->player1->getMaxRowWeight1Eval()
					<< ","
					<< this->_data->player1->getMaxRowWeight2Eval()
					<< ","
					<< this->_data->player1->getMaxRowWeight3Eval()
					<< ","
					<< this->_data->player1->getMinTime()
					<< ","
					<< this->_data->player1->getMinRowEval()
					<< ","
					<< this->_data->player1->getMinWeight1Eval()
					<< ","
					<< this->_data->player1->getMinWeight2Eval()
					<< ","
					<< this->_data->player1->getMinWeight3Eval()
					<< ","
					<< this->_data->player1->getMinRowWeight1Eval()
					<< ","
					<< this->_data->player1->getMinRowWeight2Eval()
					<< ","
					<< this->_data->player1->getMinRowWeight3Eval()
					<< ","
					<< this->_data->player1->getAverageTime()
					<< ","
					<< this->_data->player1->getAverageRowEval()
					<< ","
					<< this->_data->player1->getAverageWeight1Eval()
					<< ","
					<< this->_data->player1->getAverageWeight2Eval()
					<< ","
					<< this->_data->player1->getAverageWeight3Eval()
					<< ","
					<< this->_data->player1->getAverageRowWeight1Eval()
					<< ","
					<< this->_data->player1->getAverageRowWeight2Eval()
					<< ","
					<< this->_data->player1->getAverageRowWeight3Eval()
					<< ","
					<< this->_data->player1->getMaxRowEvalDiff()
					<< ","
					<< this->_data->player1->getMaxWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getMaxWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getMaxWeight3EvalDiff()
					<< ","
					<< this->_data->player1->getMaxRowWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getMaxRowWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getMaxRowWeight3EvalDiff()
					<< ","
					<< this->_data->player1->getMinRowEvalDiff()
					<< ","
					<< this->_data->player1->getMinWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getMinWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getMinWeight3EvalDiff()
					<< ","
					<< this->_data->player1->getMinRowWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getMinRowWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getMinRowWeight3EvalDiff()
					<< ","
					<< this->_data->player1->getAverageRowEvalDiff()
					<< ","
					<< this->_data->player1->getAverageWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getAverageWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getAverageWeight3EvalDiff()
					<< ","
					<< this->_data->player1->getAverageRowWeight1EvalDiff()
					<< ","
					<< this->_data->player1->getAverageRowWeight2EvalDiff()
					<< ","
					<< this->_data->player1->getAverageRowWeight3EvalDiff()
					<< std::endl;
				player1File.close();

				std::ofstream player2File;
				std::string fileName2 = "Board_7x4-"
					+ this->_data->player1->playerName
					+ "vs"
					+ this->_data->player2->playerName
					+ "-"
					+ this->_data->player2->playerName
					+ "2-.csv";
				player2File.open(fileName2.c_str(),
					std::ofstream::out | std::ios_base::app);

				player2File << this->_data->player2->result
					<< ","
					<< this->_data->player2->firstColumn
					<< ","
					<< this->_data->player2->getMaxTime()
					<< ","
					<< this->_data->player2->getMaxRowEval()
					<< ","
					<< this->_data->player2->getMaxWeight1Eval()
					<< ","
					<< this->_data->player2->getMaxWeight2Eval()
					<< ","
					<< this->_data->player2->getMaxWeight3Eval()
					<< ","
					<< this->_data->player2->getMaxRowWeight1Eval()
					<< ","
					<< this->_data->player2->getMaxRowWeight2Eval()
					<< ","
					<< this->_data->player2->getMaxRowWeight3Eval()
					<< ","
					<< this->_data->player2->getMinTime()
					<< ","
					<< this->_data->player2->getMinRowEval()
					<< ","
					<< this->_data->player2->getMinWeight1Eval()
					<< ","
					<< this->_data->player2->getMinWeight2Eval()
					<< ","
					<< this->_data->player2->getMinWeight3Eval()
					<< ","
					<< this->_data->player2->getMinRowWeight1Eval()
					<< ","
					<< this->_data->player2->getMinRowWeight2Eval()
					<< ","
					<< this->_data->player2->getMinRowWeight3Eval()
					<< ","
					<< this->_data->player2->getAverageTime()
					<< ","
					<< this->_data->player2->getAverageRowEval()
					<< ","
					<< this->_data->player2->getAverageWeight1Eval()
					<< ","
					<< this->_data->player2->getAverageWeight2Eval()
					<< ","
					<< this->_data->player2->getAverageWeight3Eval()
					<< ","
					<< this->_data->player2->getAverageRowWeight1Eval()
					<< ","
					<< this->_data->player2->getAverageRowWeight2Eval()
					<< ","
					<< this->_data->player2->getAverageRowWeight3Eval()
					<< ","
					<< this->_data->player2->getMaxRowEvalDiff()
					<< ","
					<< this->_data->player2->getMaxWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getMaxWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getMaxWeight3EvalDiff()
					<< ","
					<< this->_data->player2->getMaxRowWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getMaxRowWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getMaxRowWeight3EvalDiff()
					<< ","
					<< this->_data->player2->getMinRowEvalDiff()
					<< ","
					<< this->_data->player2->getMinWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getMinWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getMinWeight3EvalDiff()
					<< ","
					<< this->_data->player2->getMinRowWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getMinRowWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getMinRowWeight3EvalDiff()
					<< ","
					<< this->_data->player2->getAverageRowEvalDiff()
					<< ","
					<< this->_data->player2->getAverageWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getAverageWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getAverageWeight3EvalDiff()
					<< ","
					<< this->_data->player2->getAverageRowWeight1EvalDiff()
					<< ","
					<< this->_data->player2->getAverageRowWeight2EvalDiff()
					<< ","
					<< this->_data->player2->getAverageRowWeight3EvalDiff()
					<< std::endl;
				player2File.close();

				reported = true;

			}
			this->_data->machine.AddState(StateRef(new GameMenuState(_data)), true);
		}
	}
}

void GameState_7x4::Draw(float dt)
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