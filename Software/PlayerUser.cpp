#include <iostream>
#include "PlayerUser.hpp"
#include "RowEvalInC.h"
#include "Weight1EvalInC.h"
#include "Weight2EvalInC.h"
#include "Weight3EvalInC.h"
#include "RowWithWeight1Eval.h"
#include "RowWithWeight2Eval.h"
#include "RowWithWeight3Eval.h"

PlayerUser::PlayerUser(GameDataRef data, Discs playerDisc) : _data{ data }, _playerDisc { playerDisc }
{
	
}

void PlayerUser::nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{
	int width = WIDTH_4x4;
	int height = HEIGHT_4x4;
	sf::Vector2i mousePoint = this->_data->input.GetMousePosition(this->_data->window);
	int column = 0;
	int tempWidth = this->_data->assets.GetTexture("Empty Disc").getSize().x;
	for (int colNum = 0; colNum < width; colNum++)
	{
		if ((mousePoint.x >= colNum * tempWidth) && (mousePoint.x < (colNum + 1) * (tempWidth))) {
			column = colNum;
		}
	}

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		std::cout << "Column " << column + 1 << " is Full" << std::endl;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = _playerDisc;
				this->_data->_prevCol = column;

				if (_playerDisc == PLAYER_ONE_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player One Disc"));
				}
				else if (_playerDisc == PLAYER_TWO_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
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
	calcEvaluation(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerUser::nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{
	int width = WIDTH_7x6;
	int height = HEIGHT_7x6;
	sf::Vector2i mousePoint = this->_data->input.GetMousePosition(this->_data->window);
	int column = 0;
	int tempWidth = this->_data->assets.GetTexture("Empty Disc").getSize().x;
	for (int colNum = 0; colNum < width; colNum++)
	{
		if ((mousePoint.x >= colNum * tempWidth) && (mousePoint.x < (colNum + 1) * (tempWidth))) {
			column = colNum;
		}
	}

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		std::cout << "Column " << column + 1 << " is Full" << std::endl;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = _playerDisc;
				this->_data->_prevCol = column;

				if (_playerDisc == PLAYER_ONE_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player One Disc"));
				}
				else if (_playerDisc == PLAYER_TWO_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
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
	calcEvaluation(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerUser::nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{
	int width = WIDTH_14x12;
	int height = HEIGHT_14x12;
	sf::Vector2i mousePoint = this->_data->input.GetMousePosition(this->_data->window);
	int column = 0;
	int tempWidth = this->_data->assets.GetTexture("Empty Disc").getSize().x;
	for (int colNum = 0; colNum < width; colNum++)
	{
		if ((mousePoint.x >= colNum * tempWidth) && (mousePoint.x < (colNum + 1) * (tempWidth))) {
			column = colNum;
		}
	}

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		std::cout << "Column " << column + 1 << " is Full" << std::endl;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = _playerDisc;
				this->_data->_prevCol = column;

				if (_playerDisc == PLAYER_ONE_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player One Disc"));
				}
				else if (_playerDisc == PLAYER_TWO_DISC)
				{
					boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
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
	calcEvaluation(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

int PlayerUser::calcEvaluation(Board_4x4* board)  
{
	eval = rowEval_4x4(board);
	return eval;
}

int PlayerUser::calcEvaluation(Board_7x6* board)
{
	//eval = rowEval_7x6(board);
	//eval = weight1Eval_7x6(board);
	return eval;
}

int PlayerUser::calcEvaluation(Board_14x12* board)
{
	eval = rowEval_14x12(board);
	return eval;
}