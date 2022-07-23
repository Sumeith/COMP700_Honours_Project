#include "MiniMaxRowEvalInC.h"

int minimaxRowEval_4x4(Board_4x4* board, int depth, Discs playerDisc, int* move)
{
	int boardEval = rowEval_4x4(board);
	if (boardEval == INT_MAX || 
		boardEval == INT_MIN || depth == 0)
	{
		return boardEval;
	}
	int bestEval = boardEval;
	int tempEval;
	int bestMove = *move;
	//Maximizing Player
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestEval = INT_MIN;
		for (int col = 0; col < WIDTH_4x4; col++)
		{

			if (!isValidLoc_4x4(board, col)) { continue; }

			Board_4x4 tempBoard;
			copyBoard_4x4(board, &tempBoard);
			Dripdisc_4x4(&tempBoard, col, PLAYER_ONE_DISC);
			tempEval = minimaxRowEval_4x4(&tempBoard, depth -1, PLAYER_TWO_DISC, move);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	//Minimizing Player
	if (playerDisc == PLAYER_TWO_DISC)
	{
		bestEval = INT_MAX;
		for (int col = 0; col < WIDTH_4x4; col++)
		{
			if (!isValidLoc_4x4(board, col)) { continue; }

			Board_4x4 tempBoard;
			copyBoard_4x4(board, &tempBoard);
			Dripdisc_4x4(&tempBoard, col, PLAYER_TWO_DISC);
			tempEval = minimaxRowEval_4x4(&tempBoard, depth - 1, PLAYER_ONE_DISC, move);
			bestMove = col;

			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	*move = bestMove;
	return bestEval;
}

int minimaxRowEval_7x6(Board_7x6* board, int depth, Discs playerDisc, int* move)
{
	int boardEval = rowEval_7x6(board);
	if (boardEval == INT_MAX ||
		boardEval == INT_MIN || depth == 0)
	{
		return boardEval;
	}
	int bestEval = boardEval;
	int tempEval;
	int bestMove = 0;
	//Maximizing Player
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestEval = INT_MIN;
		for (int col = 0; col < WIDTH_7x6; col++)
		{

			if (!isValidLoc_7x6(board, col)) { continue; }

			Board_7x6 tempBoard;
			copyBoard_7x6(board, &tempBoard);
			Dripdisc_7x6(&tempBoard, col, PLAYER_ONE_DISC);
			tempEval = minimaxRowEval_7x6(&tempBoard, depth - 1, PLAYER_TWO_DISC, move);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	//Minimizing Player
	if (playerDisc == PLAYER_TWO_DISC)
	{
		bestEval = INT_MAX;
		for (int col = 0; col < WIDTH_7x6; col++)
		{
			if (!isValidLoc_7x6(board, col)) { continue; }

			Board_7x6 tempBoard;
			copyBoard_7x6(board, &tempBoard);
			Dripdisc_7x6(&tempBoard, col, PLAYER_TWO_DISC);
			tempEval = minimaxRowEval_7x6(&tempBoard, depth - 1, PLAYER_ONE_DISC, move);

			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	*move = bestMove;
	return bestEval;
}

int minimaxRowEval_14x12(Board_14x12* board, int depth, Discs playerDisc, int* move)
{
	int boardEval = rowEval_14x12(board);
	if (boardEval == INT_MAX ||
		boardEval == INT_MIN || depth == 0)
	{
		return boardEval;
	}
	int bestEval = boardEval;
	int tempEval;
	int bestMove = *move;
	//Maximizing Player
	if (playerDisc == PLAYER_ONE_DISC)
	{
		bestEval = INT_MIN;
		for (int col = 0; col < WIDTH_14x12; col++)
		{

			if (!isValidLoc_14x12(board, col)) { continue; }

			Board_14x12 tempBoard;
			copyBoard_14x12(board, &tempBoard);
			Dripdisc_14x12(&tempBoard, col, PLAYER_ONE_DISC);
			tempEval = minimaxRowEval_14x12(&tempBoard, depth - 1, PLAYER_TWO_DISC, move);
			if (tempEval> bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	//Minimizing Player
	if (playerDisc == PLAYER_TWO_DISC)
	{
		bestEval = INT_MAX;
		for (int col = 0; col < WIDTH_14x12; col++)
		{
			if (!isValidLoc_14x12(board, col)) { continue; }

			Board_14x12 tempBoard;
			copyBoard_14x12(board, &tempBoard);
			Dripdisc_14x12(&tempBoard, col, PLAYER_TWO_DISC);
			tempEval = minimaxRowEval_14x12(&tempBoard, depth - 1, PLAYER_ONE_DISC, move);
			bestMove = col;

			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
		}
	}

	*move = bestMove;
	return bestEval;
}