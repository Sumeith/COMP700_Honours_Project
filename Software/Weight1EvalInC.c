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