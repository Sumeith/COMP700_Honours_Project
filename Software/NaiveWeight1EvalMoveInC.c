#include "NaiveWeight1EvalMoveInC.h"
#include <limits.h>
int getNaiveWeight1EvalColumn_4x4(Board_4x4* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_4x4 tempBoard;
	for (int col = 0; col < WIDTH_4x4; col++)
	{
		copyBoard_4x4(board, &tempBoard);
		Dripdisc_4x4(&tempBoard, col, playerDisc);
		if (!isValidLoc_4x4(board, col)) { continue; }
		score = weight1Eval_4x4(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_7x4(Board_7x4* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_7x4 tempBoard;
	for (int col = 0; col < WIDTH_7x4; col++)
	{
		copyBoard_7x4(board, &tempBoard);
		Dripdisc_7x4(&tempBoard, col, playerDisc);
		if (!isValidLoc_7x4(board, col)) { continue; }
		score = weight1Eval_7x4(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_4x7(Board_4x7* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_4x7 tempBoard;
	for (int col = 0; col < WIDTH_4x7; col++)
	{
		copyBoard_4x7(board, &tempBoard);
		Dripdisc_4x7(&tempBoard, col, playerDisc);
		if (!isValidLoc_4x7(board, col)) { continue; }
		score = weight1Eval_4x7(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_7x6(Board_7x6* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_7x6 tempBoard;
	for (int col = 0; col < WIDTH_7x6; col++)
	{
		copyBoard_7x6(board, &tempBoard);
		Dripdisc_7x6(&tempBoard, col, playerDisc);
		if (!isValidLoc_7x6(board, col)) { continue; }
		score = weight1Eval_7x6(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_6x7(Board_6x7* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_6x7 tempBoard;
	for (int col = 0; col < WIDTH_6x7; col++)
	{
		copyBoard_6x7(board, &tempBoard);
		Dripdisc_6x7(&tempBoard, col, playerDisc);
		if (!isValidLoc_6x7(board, col)) { continue; }
		score = weight1Eval_6x7(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_8x8(Board_8x8* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_8x8 tempBoard;
	for (int col = 0; col < WIDTH_8x8; col++)
	{
		copyBoard_8x8(board, &tempBoard);
		Dripdisc_8x8(&tempBoard, col, playerDisc);
		if (!isValidLoc_8x8(board, col)) { continue; }
		score = weight1Eval_8x8(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_14x12(Board_14x12* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_14x12 tempBoard;
	for (int col = 0; col < WIDTH_14x12; col++)
	{
		copyBoard_14x12(board, &tempBoard);
		Dripdisc_14x12(&tempBoard, col, playerDisc);
		if (!isValidLoc_14x12(board, col)) { continue; }
		score = weight1Eval_14x12(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}

int getNaiveWeight1EvalColumn_12x14(Board_12x14* board, Discs playerDisc)
{
	int score;
	int bestScore;
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestScore = INT_MIN;
		score = INT_MIN;
	}
	else
	{
		bestScore = INT_MAX;
		score = INT_MAX;
	}
	int bestCol = -1;
	Board_12x14 tempBoard;
	for (int col = 0; col < WIDTH_12x14; col++)
	{
		copyBoard_12x14(board, &tempBoard);
		Dripdisc_12x14(&tempBoard, col, playerDisc);
		if (!isValidLoc_12x14(board, col)) { continue; }
		score = weight1Eval_12x14(&tempBoard);
		if (playerDisc == PLAYER_ONE_DISC)
		{
			if (score > bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			if (score < bestScore) {
				bestScore = score;
				bestCol = col;
			}
		}
	}
	return bestCol;
}
