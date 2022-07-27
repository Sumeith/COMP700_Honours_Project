#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "LeftMoveInC.h"

int getLeftColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol <= 0 || prevCol >= WIDTH_4x4)
	{
		return getRandomColumn_4x4(board);
	}
	
	
	int colPlacement = prevCol - 1;

	//if statement to determine if the left move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}

	return getRandomColumn_4x4(board);
}

int getLeftColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol <= 0 || prevCol >= WIDTH_7x6)
	{
		return getRandomColumn_7x6(board);
	}


	int colPlacement = prevCol - 1;

	//if statement to determine if the left move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}

	return getRandomColumn_7x6(board);
}

int getLeftColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol <= 0 || prevCol >= WIDTH_14x12)
	{
		return getRandomColumn_14x12(board);
	}


	int colPlacement = prevCol - 1;

	//if statement to determine if the left move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}

	return getRandomColumn_14x12(board);
}