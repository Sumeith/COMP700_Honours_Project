#include "PlayerMiniMaxABRowWeight2Eval.hpp"
#include "RowEvalInC.h"
#include "Weight1EvalInC.h"
#include "Weight2EvalInC.h"
#include "Weight3EvalInC.h"
#include "RowWithWeight1Eval.h"
#include "RowWithWeight2Eval.h"
#include "RowWithWeight3Eval.h"

PlayerMiniMaxABRowWeight2Eval::PlayerMiniMaxABRowWeight2Eval(GameDataRef data, Discs playerDisc) : _data{ data }, _playerDisc{ playerDisc }
{

}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_4x4(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
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

	calcEvaluation_4x4(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_7x4* board, sf::Sprite boardPieces[HEIGHT_7x4][WIDTH_7x4])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_7x4(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_7x4;
	int height = HEIGHT_7x4;

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

	calcEvaluation_7x4(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_4x7* board, sf::Sprite boardPieces[HEIGHT_4x7][WIDTH_4x7])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_4x7(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_4x7;
	int height = HEIGHT_4x7;

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

	calcEvaluation_4x7(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_7x6(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
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

	calcEvaluation_7x6(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_6x7* board, sf::Sprite boardPieces[HEIGHT_6x7][WIDTH_6x7])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_6x7(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_6x7;
	int height = HEIGHT_6x7;

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

	calcEvaluation_6x7(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_8x8* board, sf::Sprite boardPieces[HEIGHT_8x8][WIDTH_8x8])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_8x8(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_8x8;
	int height = HEIGHT_8x8;

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

	calcEvaluation_8x8(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_14x12(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
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

	calcEvaluation_14x12(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}

void PlayerMiniMaxABRowWeight2Eval::nextMove(Board_12x14* board, sf::Sprite boardPieces[HEIGHT_12x14][WIDTH_12x14])
{
	int colPlacement;
	int depth = INT_MAX;
	int eval;
	minimaxABRowWeight2Eval_12x14(board, depth, INT_MIN, INT_MAX, _playerDisc, &colPlacement, &eval);
	this->_data->_prevCol = colPlacement;
	int width = WIDTH_12x14;
	int height = HEIGHT_12x14;

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

	calcEvaluation_12x14(board);
	if (eval == PLAYER_ONE_WINS)
	{
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		this->_data->_gameOver = true;
	}
}


void PlayerMiniMaxABRowWeight2Eval::updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{

}

void PlayerMiniMaxABRowWeight2Eval::updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{

}

void PlayerMiniMaxABRowWeight2Eval::updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{

}
