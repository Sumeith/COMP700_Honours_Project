#include "GameFuncInC.h"

void Dripdisc_4x4(Board_4x4 *board, int column, Discs playerDisc)
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

void Dripdisc_7x4(Board_7x4* board, int column, Discs playerDisc)
{
	int width = WIDTH_7x4;
	int height = HEIGHT_7x4;

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

void Dripdisc_4x7(Board_4x7* board, int column, Discs playerDisc)
{
	int width = WIDTH_4x7;
	int height = HEIGHT_4x7;

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

void Dripdisc_7x6(Board_7x6* board, int column, Discs playerDisc)
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

void Dripdisc_6x7(Board_6x7* board, int column, Discs playerDisc)
{
	int width = WIDTH_6x7;
	int height = HEIGHT_6x7;

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

void Dripdisc_8x8(Board_8x8* board, int column, Discs playerDisc)
{
	int width = WIDTH_8x8;
	int height = HEIGHT_8x8;

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

void Dripdisc_14x12(Board_14x12* board, int column, Discs playerDisc)
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

void Dripdisc_12x14(Board_12x14* board, int column, Discs playerDisc)
{
	int width = WIDTH_12x14;
	int height = HEIGHT_12x14;

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

void copyBoard_4x4(Board_4x4* board, Board_4x4 *copy)
{
	for (int row = 0; row < HEIGHT_4x4; row++)
	{
		for (int col = 0; col < WIDTH_4x4; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_7x4(Board_7x4* board, Board_7x4* copy)
{
	for (int row = 0; row < HEIGHT_7x4; row++)
	{
		for (int col = 0; col < WIDTH_7x4; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_4x7(Board_4x7* board, Board_4x7* copy)
{
	for (int row = 0; row < HEIGHT_4x7; row++)
	{
		for (int col = 0; col < WIDTH_4x7; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_7x6(Board_7x6* board, Board_7x6 *copy)
{
	for (int row = 0; row < HEIGHT_7x6; row++)
	{
		for (int col = 0; col < WIDTH_7x6; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_6x7(Board_6x7* board, Board_6x7* copy)
{
	for (int row = 0; row < HEIGHT_6x7; row++)
	{
		for (int col = 0; col < WIDTH_6x7; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_8x8(Board_8x8* board, Board_8x8* copy)
{
	for (int row = 0; row < HEIGHT_8x8; row++)
	{
		for (int col = 0; col < WIDTH_8x8; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_14x12(Board_14x12* board, Board_14x12 *copy)
{
	for (int row = 0; row < HEIGHT_14x12; row++)
	{
		for (int col = 0; col < WIDTH_14x12; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

void copyBoard_12x14(Board_12x14* board, Board_12x14* copy)
{
	for (int row = 0; row < HEIGHT_12x14; row++)
	{
		for (int col = 0; col < WIDTH_12x14; col++)
		{
			copy->_grid[row][col] = board->_grid[row][col];
		}
	}
}

bool isValidLoc_4x4(Board_4x4* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_7x4(Board_7x4* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_4x7(Board_4x7* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_7x6(Board_7x6* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_6x7(Board_6x7* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_8x8(Board_8x8* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_14x12(Board_14x12* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isValidLoc_12x14(Board_12x14* board, int col)
{
	return board->_grid[0][col] == EMPTY_DISC;
}

bool isGameOver_4x4(Board_4x4* board)
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

bool isGameOver_7x4(Board_7x4* board)
{
	for (int col = 0; col < WIDTH_7x4; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_4x7(Board_4x7* board)
{
	for (int col = 0; col < WIDTH_4x7; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_7x6(Board_7x6* board)
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

bool isGameOver_6x7(Board_6x7* board)
{
	for (int col = 0; col < WIDTH_6x7; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_8x8(Board_8x8* board)
{
	for (int col = 0; col < WIDTH_8x8; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}

bool isGameOver_14x12(Board_14x12* board)
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

bool isGameOver_12x14(Board_12x14* board)
{
	for (int col = 0; col < WIDTH_12x14; col++)
	{
		if (board->_grid[0][col] == EMPTY_DISC)
		{
			return false;
		}
	}
	return true;
}
