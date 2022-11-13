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

int getSameColumn_7x4(Board_7x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_7x4)
	{
		return getRandomColumn_7x4(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_7x4(board);
	}
}

int getSameColumn_4x7(Board_4x7* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_4x7)
	{
		return getRandomColumn_4x7(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_4x7(board);
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

int getSameColumn_6x7(Board_6x7* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_6x7)
	{
		return getRandomColumn_6x7(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_6x7(board);
	}
}

int getSameColumn_8x8(Board_8x8* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_8x8)
	{
		return getRandomColumn_8x8(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_8x8(board);
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

int getSameColumn_12x14(Board_12x14* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_12x14)
	{
		return getRandomColumn_12x14(board);
	}
	int prevColPlacement = prevCol;
	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
	{
		return prevColPlacement;
	}
	else
	{
		return getRandomColumn_12x14(board);
	}
}