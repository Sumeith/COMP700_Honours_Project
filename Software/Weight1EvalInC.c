#include "Weight1EvalInC.h"
#include "HeuristicsWeights.h"
int weight1Eval_4x4(Board_4x4* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_4x4; row++)
	{
		for (int col = 0; col < WIDTH_4x4; col++)
		{
			eval += board->_grid[row][col] * weight1_4x4[row][col];
		}
	}
	return eval;
}

int weight1Eval_7x4(Board_7x4* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_7x4; row++)
	{
		for (int col = 0; col < WIDTH_7x4; col++)
		{
			eval += board->_grid[row][col] * weight1_7x4[row][col];
		}
	}
	return eval;
}

int weight1Eval_4x7(Board_4x7* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_4x7; row++)
	{
		for (int col = 0; col < WIDTH_4x7; col++)
		{
			eval += board->_grid[row][col] * weight1_4x7[row][col];
		}
	}
	return eval;
}

int weight1Eval_7x6(Board_7x6* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_7x6; row++)
	{
		for (int col = 0; col < WIDTH_7x6; col++)
		{
			eval += board->_grid[row][col] * weight1_7x6[row][col];
		}
	}
	return eval;
}

int weight1Eval_6x7(Board_6x7* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_6x7; row++)
	{
		for (int col = 0; col < WIDTH_6x7; col++)
		{
			eval += board->_grid[row][col] * weight1_6x7[row][col];
		}
	}
	return eval;
}

int weight1Eval_8x8(Board_8x8* board)

{
	int eval = 0;

	for (int row = 0; row < HEIGHT_8x8; row++)
	{
		for (int col = 0; col < WIDTH_8x8; col++)
		{
			eval += board->_grid[row][col] * weight1_8x8[row][col];
		}
	}
	return eval;
}

int weight1Eval_14x12(Board_14x12* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_14x12; row++)
	{
		for (int col = 0; col < WIDTH_14x12; col++)
		{
			eval += board->_grid[row][col] * weight1_14x12[row][col];
		}
	}
	return eval;
}

int weight1Eval_12x14(Board_12x14* board)
{
	int eval = 0;

	for (int row = 0; row < HEIGHT_12x14; row++)
	{
		for (int col = 0; col < WIDTH_12x14; col++)
		{
			eval += board->_grid[row][col] * weight1_12x14[row][col];
		}
	}
	return eval;
}