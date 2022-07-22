#include "NaiveRowEvalMoveInC.h"
#include <limits.h>
int getNaiveRowEvalColumn_4x4(Board_4x4* board, Discs playerDisc)
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
		score = rowEval_4x4(&tempBoard);
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

int getNaiveRowEvalColumn_7x6(Board_7x6* board, Discs playerDisc)
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
		score = rowEval_7x6(&tempBoard);
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

int getNaiveRowEvalColumn_14x12(Board_14x12* board, Discs playerDisc)
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
		score = rowEval_14x12(&tempBoard);
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