#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "RightMoveInC.h"

int getRightColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_4x4)
	{
		return getRandomColumn_4x4(board);
	}

	for (int col = prevCol + 1; col < WIDTH_4x4; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % (WIDTH_4x4 - prevCol) + prevCol + 2;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_4x4(board);
}

int getRightColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_7x6)
	{
		return getRandomColumn_7x6(board);
	}

	for (int col = prevCol + 1; col < WIDTH_7x6; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % (WIDTH_7x6 - prevCol) + prevCol + 2;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_7x6(board);
}

int getRightColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_14x12)
	{
		return getRandomColumn_14x12(board);
	}

	for (int col = prevCol + 1; col < WIDTH_14x12; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % (WIDTH_14x12 - prevCol) + prevCol + 2;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_14x12(board);
}