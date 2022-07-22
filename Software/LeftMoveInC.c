#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "LeftMoveInC.h"

int getLeftColumn_4x4(Board_4x4* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_4x4)
	{
		return getRandomColumn_4x4(board);
	}
	
	for (int col = 0; col < prevCol; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % prevCol;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_4x4(board);
}

int getLeftColumn_7x6(Board_7x6* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_7x6)
	{
		return getRandomColumn_7x6(board);
	}

	for (int col = 0; col < prevCol; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % prevCol;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_7x6(board);
}

int getLeftColumn_14x12(Board_14x12* board, int prevCol)
{
	//if statement to determine if the prevColomn is invalid
	if (prevCol < 0 || prevCol >= WIDTH_14x12)
	{
		return getRandomColumn_14x12(board);
	}

	for (int col = 0; col < prevCol; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			while (true)
			{
				int colPlacement = rand() % prevCol;
				if (board->_grid[0][colPlacement] == EMPTY_DISC)
				{
					return colPlacement;
				}
			}
		}
	}
	return getRandomColumn_14x12(board);
}