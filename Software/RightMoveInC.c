#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "RightMoveInC.h"

int getRightColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_4x4 - 1))
	{
		return getRandomColumn_4x4(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_4x4(board);
}

int getRightColumn_7x4(Board_7x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_7x4 - 1))
	{
		return getRandomColumn_7x4(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_7x4(board);
}

int getRightColumn_4x7(Board_4x7* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_4x7 - 1))
	{
		return getRandomColumn_4x7(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_4x7(board);
}

int getRightColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_7x6 - 1))
	{
		return getRandomColumn_7x6(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_7x6(board);
}

int getRightColumn_6x7(Board_6x7* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_6x7 - 1))
	{
		return getRandomColumn_6x7(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_6x7(board);
}

int getRightColumn_8x8(Board_8x8* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_8x8 - 1))
	{
		return getRandomColumn_8x8(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_8x8(board);
}

int getRightColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_14x12 - 1))
	{
		return getRandomColumn_14x12(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_14x12(board);
}

int getRightColumn_12x14(Board_12x14* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= (WIDTH_12x14 - 1))
	{
		return getRandomColumn_12x14(board);
	}

	int colPlacement = prevCol + 1;

	//if statement to determine if the right move is available
	if (board->_grid[0][colPlacement] == EMPTY_DISC)
	{
		return colPlacement;
	}
	return getRandomColumn_12x14(board);
}
