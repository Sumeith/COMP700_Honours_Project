#include "NegaMaxRowEvalInC.h"

void negamaxRowEval_4x4(Board_4x4* board, int depth, Discs playerDisc, int* move, int* eval)
{
	return;
}

void negamaxRowEval_7x6(Board_7x6* board, int depth, Discs playerDisc, int* move, int *eval)
{
	if (isGameOver_7x6(board) ||
		depth == 0)
	{
		*eval = rowEval_7x6(board);
		return;
	}

	int bestEval = INT_MIN;
	int bestMove = -1;

	for (int col = 0; col < WIDTH_7x6; col++)
	{
		if (!isValidLoc_7x6(board, col)) { continue; }

		Board_7x6 tempboard;
		copyBoard_7x6(board, &tempboard);
		Dripdisc_7x6(&tempboard, col, playerDisc);
		int tempEval;
		int tempMove = -1;

		//Discs oppoonentDisc = playerDisc == PLAYER_ONE_DISC ? PLAYER_TWO_DISC : PLAYER_ONE_DISC;

		negamaxRowEval_7x6(&tempboard, depth - 1, playerDisc, &tempMove, &tempEval);
		tempEval *= playerDisc;
		//int currentEval = -tempEval;

		if (tempEval > bestEval)
		{
			bestEval = tempEval;
			bestMove = col;
		}
	}
	*move = bestMove;
	*eval = bestEval * -1;
	return;
}

void negamaxRowEval_14x12(Board_14x12* board, int depth, Discs playerDisc, int* move, int* eval)
{

}