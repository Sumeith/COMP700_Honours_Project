#include "RowEvalInC.h"
#include <limits.h>


int rowEval_4x4(Board_4x4* board)
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
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
}

int rowEval_7x6(Board_7x6* board)
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
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
}

int rowEval_14x12(Board_14x12* board)
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
		THREE_IN_A_ROW_VALUE * evalArr[5] - TWO_IN_A_ROW_VALUE * evalArr[4] - evalArr[3];
}

int checkConditionHorizontal(int col, int width)
{
	return col < (width - 3);
}

int checkConditionVertical(int row, int height)
{
	return row < (height - 3);
}

int checkConditionPosDiag(int row, int col, int width)
{
	return row >= 3 && col < (width - 3);
}

int checkConditionNegDiag(int row, int col, int height, int width)
{
	return col < (width - 3) && row < (height - 3);
}

/*
* This function checks if there are 3 Discs in a winning position for a player
* and updates the evlauation array accordingly.
*
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position
*
* This function looks for the following combinations:
* Disc Disc Disc _
* Disc Disc _ Disc
* Disc _ Disc Disc
* _ Disc Disc Disc
*/
void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc Disc Disc _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[0]++;
	}
	//Disc Disc Disc _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[5]++;
	}

	//Disc Disc _ Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//Disc Disc _ Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}

	//Disc _ Disc Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//Disc _ Disc Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}

	//_ Disc Disc Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//_ Disc Disc Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}
}

/*
* This function checks if there are 2 Discs in a winning position for a player
* and updates the evlauation array accordingly.
*
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position
*
* This function looks for the following combinations:
* Disc Disc _ _
* Disc _ Disc _
* Disc _ _ Disc
* _ Disc Disc _
* _ Disc _ Disc
* _ _ Disc Disc
*/
void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc Disc _ _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//Disc Disc _ _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//Disc _ Disc _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//Disc _ Disc _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//Disc _ _ Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//Disc _ _ Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}

	//_ Disc Disc _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//_ Disc Disc _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//_ Disc _ Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//_ Disc _ Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}

	//_ _ Disc Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//_ _ Disc Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}
}

/*
* This function checks if there are 1 Disc in a winning position for a player
* and updates the evlauation array accordingly.
*
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position
*
* This function looks for the following combinations:
* Disc _ _ _
* _ Disc _ _
* _ _ Disc _
* _ _ _ Disc
*/
void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc _ _ _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//Disc _ _ _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ Disc _ _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//_ Disc _ _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ _ Disc _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//_ _ Disc _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ _ _ Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[2]++;
	}
	//_ _ _ Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[3]++;
	}
}