#include "PlayerNegaMaxRowEval.hpp"
#include "RowEvalInC.h"
#include "Weight1EvalInC.h"
#include "Weight2EvalInC.h"
#include "Weight3EvalInC.h"
#include "RowWithWeight1Eval.h"
#include "RowWithWeight2Eval.h"
#include "RowWithWeight3Eval.h"

PlayerNegaMaxRowEval::PlayerNegaMaxRowEval(GameDataRef data, Discs playerDisc) : _data{ data }, _playerDisc{ playerDisc }
{

}

void PlayerNegaMaxRowEval::nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	negamaxRowEval_4x4(board, depth, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_4x4;
	int height = HEIGHT_4x4;

	for (int row = height - 1; row >= 0; row--)
	{
		if (board->_grid[row][colPlacement] == EMPTY_DISC)
		{
			board->_grid[row][colPlacement] = _playerDisc;

			if (_playerDisc == PLAYER_ONE_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player One Disc"));
			}
			else if (_playerDisc == PLAYER_TWO_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
			}
			else
			{
				std::cout << "Invalid Disc" << std::endl;
			}
			break;
		}
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

void PlayerNegaMaxRowEval::nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{
	int colPlacement;
	int depth = 1;
	int eval;
	negamaxRowEval_7x6(board, depth, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_7x6;
	int height = HEIGHT_7x6;

	for (int row = height - 1; row >= 0; row--)
	{
		if (board->_grid[row][colPlacement] == EMPTY_DISC)
		{
			board->_grid[row][colPlacement] = _playerDisc;

			if (_playerDisc == PLAYER_ONE_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player One Disc"));
			}
			else if (_playerDisc == PLAYER_TWO_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
			}
			else
			{
				std::cout << "Invalid Disc" << std::endl;
			}
			break;
		}
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

void PlayerNegaMaxRowEval::nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	negamaxRowEval_14x12(board, depth, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_14x12;
	int height = HEIGHT_14x12;

	for (int row = height - 1; row >= 0; row--)
	{
		if (board->_grid[row][colPlacement] == EMPTY_DISC)
		{
			board->_grid[row][colPlacement] = _playerDisc;

			if (_playerDisc == PLAYER_ONE_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player One Disc"));
			}
			else if (_playerDisc == PLAYER_TWO_DISC)
			{
				boardPieces[row][colPlacement].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
			}
			else
			{
				std::cout << "Invalid Disc" << std::endl;
			}
			break;
		}
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

int PlayerNegaMaxRowEval::calcEvaluation(Board_4x4* board)
{
	eval = rowEval_4x4(board);
	return eval;
}

int PlayerNegaMaxRowEval::calcEvaluation(Board_7x6* board)
{
	eval = rowEval_7x6(board);
	return eval;
}

int PlayerNegaMaxRowEval::calcEvaluation(Board_14x12* board)
{
	eval = rowEval_14x12(board);
	return eval;
}

void PlayerNegaMaxRowEval::updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{

}

void PlayerNegaMaxRowEval::updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{

}

void PlayerNegaMaxRowEval::updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{

}
