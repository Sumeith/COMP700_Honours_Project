#include "PlayerLeft.hpp"
#include "RowEvalInC.h"
#include "Weight1EvalInC.h"
#include "Weight2EvalInC.h"
#include "Weight3EvalInC.h"
#include "RowWithWeight1Eval.h"
#include "RowWithWeight2Eval.h"
#include "RowWithWeight3Eval.h"

PlayerLeft::PlayerLeft(GameDataRef data, Discs playerDisc) : _data{ data }, _playerDisc{ playerDisc }
{
	playerName = "PlayerLeft";
}

void PlayerLeft::nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{
	calcEvaluation_4x4(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_4x4(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_7x4* board, sf::Sprite boardPieces[HEIGHT_7x4][WIDTH_7x4])
{
	calcEvaluation_7x4(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_7x4(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_4x7* board, sf::Sprite boardPieces[HEIGHT_4x7][WIDTH_4x7])
{
	calcEvaluation_4x7(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_4x7(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{
	calcEvaluation_7x6(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_7x6(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_6x7* board, sf::Sprite boardPieces[HEIGHT_6x7][WIDTH_6x7])
{
	calcEvaluation_6x7(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_6x7(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_8x8* board, sf::Sprite boardPieces[HEIGHT_8x8][WIDTH_8x8])
{
	calcEvaluation_8x8(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_8x8(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{
	calcEvaluation_14x12(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_14x12(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}

void PlayerLeft::nextMove(Board_12x14* board, sf::Sprite boardPieces[HEIGHT_12x14][WIDTH_12x14])
{
	calcEvaluation_12x14(board);
	int initialRowEval = rowEval;
	int initialWeight1Eval = weight1Eval;
	int initialWeight2Eval = weight2Eval;
	int initialWeight3Eval = weight3Eval;
	int initialRowWeight1Eval = rowWeight1Eval;
	int initialRowWeight2Eval = rowWeight2Eval;
	int initialRowWeight3Eval = rowWeight3Eval;

	auto start = std::chrono::high_resolution_clock::now();
	int colPlacement = getLeftColumn_12x14(board, this->_data->_prevCol);
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	timeVector.push_back(duration.count()); if (firstColumn < 0){firstColumn = colPlacement;}

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

	rowEvalVector.push_back(rowEval);
	weight1EvalVector.push_back(weight1Eval);
	weight2EvalVector.push_back(weight2Eval);
	weight3EvalVector.push_back(weight3Eval);
	rowWeight1EvalVector.push_back(rowWeight1Eval);
	rowWeight2EvalVector.push_back(rowWeight2Eval);
	rowWeight3EvalVector.push_back(rowWeight3Eval);

	rowEvalDiff.push_back(rowEval - initialRowEval);
	weight1EvalDiff.push_back(weight1Eval - initialWeight1Eval);
	weight2EvalDiff.push_back(weight2Eval - initialWeight2Eval);
	weight3EvalDiff.push_back(weight3Eval - initialWeight3Eval);
	rowWeight1EvalDiff.push_back(rowWeight1Eval - initialRowWeight1Eval);
	rowWeight2EvalDiff.push_back(rowWeight2Eval - initialRowWeight2Eval);
	rowWeight3EvalDiff.push_back(rowWeight3Eval - initialRowWeight3Eval);

	displayResult();

	if (eval == PLAYER_ONE_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
	if (eval == PLAYER_TWO_WINS)
	{
		result = 1;
		this->_data->_gameOver = true;
	}
}



void PlayerLeft::updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{

}

void PlayerLeft::updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{

}
void PlayerLeft::updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{

}

