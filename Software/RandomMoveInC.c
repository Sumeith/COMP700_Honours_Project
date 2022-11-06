#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "RandomMoveinC.h"

int getRandomColumn_4x4(Board_4x4 *board)
{
	bool foundColumn = false;
	int colPlacement;
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

int getRandomColumn_7x4(Board_7x4* board)
{
	bool foundColumn = false;
	int colPlacement;
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_7x4 + 1);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}

int getRandomColumn_4x7(Board_4x7* board)
{
	bool foundColumn = false;
	int colPlacement;
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_4x7 + 1);
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
	//srand(time(0));
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

int getRandomColumn_6x7(Board_6x7* board)
{
	bool foundColumn = false;
	int colPlacement;
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_6x7 + 1);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}

int getRandomColumn_8x8(Board_8x8* board)
{
	bool foundColumn = false;
	int colPlacement;
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_8x8 + 1);
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
	//srand(time(0));
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

int getRandomColumn_12x14(Board_12x14 *board)
{
	bool foundColumn = false;
	int colPlacement;
	
	while (!foundColumn)
	{
		colPlacement = rand() % (WIDTH_12x14 + 1);
		if (board->_grid[0][colPlacement] == EMPTY_DISC)
		{
			foundColumn = true;
		}
	}
	return colPlacement;
}