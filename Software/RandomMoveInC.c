#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "RandomMoveinC.h"

int getRandomColumn_4x4(Board_4x4 *board)
{
	bool foundColumn = false;
	int colPlacement;
	srand(time(0));
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_4x4 + 1);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}

int getRandomColumn_7x6(Board_7x6 *board)
{
	bool foundColumn = false;
	int colPlacement;
	srand(time(0));
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_7x6);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}

int getRandomColumn_14x12(Board_14x12 *board)
{
	bool foundColumn = false;
	int colPlacement;
	srand(time(0));
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_14x12 + 1);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}