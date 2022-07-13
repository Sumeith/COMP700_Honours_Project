#include "PlayerRandom.hpp"
#include <iostream>

PlayerRandom::PlayerRandom(GameDataRef data, Discs playerDisc) : _data{ data }, _playerDisc{ playerDisc }
{

}

void PlayerRandom::nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{
	int colPlacement = getRandomColumn_4x4(board);
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

void PlayerRandom::nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{
	int colPlacement = getRandomColumn_7x6(board);
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

void PlayerRandom::nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{
	int colPlacement = getRandomColumn_14x12(board);
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

int PlayerRandom::calcEvaluation(Board_4x4* board)
{
	int height = HEIGHT_4x4;
	int width = WIDTH_4x4;
	int evalArr[6] = { 0,0,0,0,0,0 };
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);
			}

			if (checkConditionVertical(row, height))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);
			}

			if (checkConditionPosDiag(row, col, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);
			}

			if (checkConditionNegDiag(row, col, height, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);
			}
		}
	}
	eval = THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
	return eval;
}

int PlayerRandom::calcEvaluation(Board_7x6* board)
{
	int height = HEIGHT_7x6;
	int width = WIDTH_7x6;
	int evalArr[6] = { 0,0,0,0,0,0 };
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);
			}

			if (checkConditionVertical(row, height))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);
			}

			if (checkConditionPosDiag(row, col, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);
			}

			if (checkConditionNegDiag(row, col, height, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);
			}
		}
	}
	eval = THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
	return eval;
}

int PlayerRandom::calcEvaluation(Board_14x12* board)
{
	int height = HEIGHT_14x12;
	int width = WIDTH_14x12;
	int evalArr[6] = { 0,0,0,0,0,0 };
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row][col + 1],
					board->_grid[row][col + 2],
					board->_grid[row][col + 3],
					evalArr);
			}

			if (checkConditionVertical(row, height))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col],
					board->_grid[row + 2][col],
					board->_grid[row + 3][col],
					evalArr);
			}

			if (checkConditionPosDiag(row, col, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row - 1][col + 1],
					board->_grid[row - 2][col + 2],
					board->_grid[row - 3][col + 3],
					evalArr);
			}

			if (checkConditionNegDiag(row, col, height, width))
			{
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_ONE_DISC)
				{
					eval = INT_MAX;
					return eval;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					eval = INT_MIN;
					return eval;
				}

				checkThreeInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkTwoInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);

				checkOneInARow(board->_grid[row][col],
					board->_grid[row + 1][col + 1],
					board->_grid[row + 2][col + 2],
					board->_grid[row + 3][col + 3],
					evalArr);
			}
		}
	}
	eval = THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
	return eval;
}

void PlayerRandom::updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4])
{

}

void PlayerRandom::updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6])
{

}
void PlayerRandom::updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12])
{

}
