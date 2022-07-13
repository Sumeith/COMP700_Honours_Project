#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "SymmetricMoveinC.h"

int getSymmetricColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_4x4)
	{
		return getRandomColumn_4x4(board);
	}
	int prevColPlacement = WIDTH_4x4 - prevCol - 1;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_4x4(board);
	}
}

int getSymmetricColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_7x6)
	{
		return getRandomColumn_7x6(board);
	}
	int prevColPlacement = WIDTH_7x6 - prevCol - 1;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_7x6(board);
	}
}

int getSymmetricColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_14x12)
	{
		return getRandomColumn_14x12(board);
	}
	int prevColPlacement = WIDTH_14x12 - prevCol - 1;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_14x12(board);
	}
}