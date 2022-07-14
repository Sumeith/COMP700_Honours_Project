#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "SameColumnMoveInC.h"

int getSameColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_4x4)
	{
		return getRandomColumn_4x4(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_4x4(board);
	}
}

int getSameColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_7x6)
	{
		return getRandomColumn_7x6(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_7x6(board);
	}
}

int getSameColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_14x12)
	{
		return getRandomColumn_14x12(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_14x12(board);
	}
}