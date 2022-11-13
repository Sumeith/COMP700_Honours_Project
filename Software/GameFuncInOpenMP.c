#include "GameFuncInOpenMP.h"

void Dripdisc_openMP_4x4(Board_4x4* board, int column, Discs playerDisc)
{
	int width = WIDTH_4x4;
	int height = HEIGHT_4x4;

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		return;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = playerDisc;
				break;
			}
		}
	}
}

void Dripdisc_openMP_7x6(Board_7x6* board, int column, Discs playerDisc)
{
	int width = WIDTH_7x6;
	int height = HEIGHT_7x6;

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		return;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = playerDisc;
				break;
			}
		}
	}
}

void Dripdisc_openMP_14x12(Board_14x12* board, int column, Discs playerDisc)
{
	int width = WIDTH_14x12;
	int height = HEIGHT_14x12;

	if (board->_grid[0][column] != EMPTY_DISC)
	{
		return;
	}
	else if (0 <= column && column <= width)
	{
		for (int row = height - 1; row >= 0; row--)
		{
			if (board->_grid[row][column] == EMPTY_DISC)
			{
				board->_grid[row][column] = playerDisc;
				break;
			}
		}
	}
}

void copyBoard_openMP_4x4(Board_4x4* board, Board_4x4* copy)
{
	int row;
	int col;
	#pragma omp parallel for collapse(2) private(row, col)
	for (row = 0; row < HEIGHT_4x4; row++)
	{
		for (col = 0; col < WIDTH_4x4; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_openMP_7x6(Board_7x6* board, Board_7x6* copy)
{
	for (int row = 0; row < HEIGHT_7x6; row++)
	{
		for (int col = 0; col < WIDTH_7x6; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_openMP_14x12(Board_14x12* board, Board_14x12* copy)
{
	for (int row = 0; row < HEIGHT_14x12; row++)
	{
		for (int col = 0; col < WIDTH_14x12; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

bool isValidLoc_openMP_4x4(Board_4x4* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_openMP_7x6(Board_7x6* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_openMP_14x12(Board_14x12* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isGameOver_openMP_4x4(Board_4x4* board)
{
	for (int col = 0; col < WIDTH_4x4; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_openMP_7x6(Board_7x6* board)
{
	for (int col = 0; col < WIDTH_7x6; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_openMP_14x12(Board_14x12* board)
{
	for (int col = 0; col < WIDTH_14x12; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}