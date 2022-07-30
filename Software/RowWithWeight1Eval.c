#include "RowWithWeight1Eval.h"
#include "RowEvalInC.h"
#include "HeuristicsWeights.h"

int rowWeight1Eval_4x4(Board_4x4* board)
{
	int height = HEIGHT_4x4;
	int width = WIDTH_4x4;
	int evalArr[6] = { 0,0,0,0,0,0 };
	int eval = 0;
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			eval += board->_grid[row][col] * weight1_4x4[row][col];

			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					return INT_MAX;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
	return THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3] + eval;
}

int rowWeight1_7x6(Board_7x6* board)
{
	int height = HEIGHT_7x6;
	int width = WIDTH_7x6;
	int evalArr[6] = { 0,0,0,0,0,0 };
	int eval = 0;
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			eval += board->_grid[row][col] * weight1_7x6[row][col];

			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					return INT_MAX;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
	return THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3] + eval;
}

int rowWeight1_14x12(Board_14x12* board)
{
	int height = HEIGHT_14x12;
	int width = WIDTH_14x12;
	int evalArr[6] = { 0,0,0,0,0,0 };
	int eval = 0;
	for (int col = 0; col < width; col++)
	{
		for (int row = 0; row < height; row++)
		{
			eval += board->_grid[row][col] * weight1_14x12[row][col];

			//check Horizontal
			if (checkConditionHorizontal(col, width)) {
				//check four in a row
				if (board->_grid[row][col] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 1] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 2] == PLAYER_ONE_DISC &&
					board->_grid[row][col + 3] == PLAYER_ONE_DISC)
				{
					return INT_MAX;
				}
				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row - 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row - 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row - 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
					return INT_MAX;
				}

				else if (board->_grid[row][col] == PLAYER_TWO_DISC &&
					board->_grid[row + 1][col + 1] == PLAYER_TWO_DISC &&
					board->_grid[row + 2][col + 2] == PLAYER_TWO_DISC &&
					board->_grid[row + 3][col + 3] == PLAYER_TWO_DISC)
				{
					return INT_MIN;
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
	return THREE_IN_A_ROW_VALUE * evalArr[0] + TWO_IN_A_ROW_VALUE * evalArr[1] + evalArr[2] -
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3] + eval;
}