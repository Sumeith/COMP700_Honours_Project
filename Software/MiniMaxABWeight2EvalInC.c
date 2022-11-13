#include "minimaxABWeight2EvalInC.h"

void minimaxABWeight2Eval_4x4(Board_4x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_4x4(board) ||
		depth == 0)
	{
		*eval = weight2Eval_4x4(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_4x4; col++)
	{

		if (!isValidLoc_4x4(board, col)) { continue; }

		Board_4x4 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_4x4(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_4x4(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_4x4(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_4x4(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_4x4(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_7x4(Board_7x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_7x4(board) ||
		depth == 0)
	{
		*eval = weight2Eval_7x4(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_7x4; col++)
	{

		if (!isValidLoc_7x4(board, col)) { continue; }

		Board_7x4 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_7x4(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_7x4(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_7x4(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_7x4(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_7x4(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_4x7(Board_4x7* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_4x7(board) ||
		depth == 0)
	{
		*eval = weight2Eval_4x7(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_4x7; col++)
	{

		if (!isValidLoc_4x7(board, col)) { continue; }

		Board_4x7 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_4x7(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_4x7(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_4x7(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_4x7(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_4x7(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_7x6(Board_7x6* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_7x6(board) ||
		depth == 0)
	{
		*eval = weight2Eval_7x6(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_7x6; col++)
	{

		if (!isValidLoc_7x6(board, col)) { continue; }

		Board_7x6 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_7x6(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_7x6(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_7x6(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_6x7(Board_6x7* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_6x7(board) ||
		depth == 0)
	{
		*eval = weight2Eval_6x7(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_6x7; col++)
	{

		if (!isValidLoc_6x7(board, col)) { continue; }

		Board_6x7 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_6x7(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_6x7(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_6x7(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_6x7(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_6x7(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_8x8(Board_8x8* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_8x8(board) ||
		depth == 0)
	{
		*eval = weight2Eval_8x8(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_8x8; col++)
	{

		if (!isValidLoc_8x8(board, col)) { continue; }

		Board_8x8 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_8x8(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_8x8(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_8x8(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_8x8(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_8x8(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_14x12(Board_14x12* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_14x12(board) ||
		depth == 0)
	{
		*eval = weight2Eval_14x12(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_14x12; col++)
	{

		if (!isValidLoc_14x12(board, col)) { continue; }

		Board_14x12 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_14x12(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_14x12(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_14x12(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}

void minimaxABWeight2Eval_12x14(Board_12x14* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_12x14(board) ||
		depth == 0)
	{
		*eval = weight2Eval_12x14(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_12x14; col++)
	{

		if (!isValidLoc_12x14(board, col)) { continue; }

		Board_12x14 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_12x14(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_12x14(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABWeight2Eval_12x14(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
			if (tempEval > bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}

			alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }
		}

		//Minimizing Player
		else if (playerDisc == PLAYER_TWO_DISC)
		{
			Dripdisc_12x14(&tempBoard, col, PLAYER_TWO_DISC);
			minimaxABWeight2Eval_12x14(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
			if (tempEval < bestEval)
			{
				bestMove = col;
				bestEval = tempEval;
			}
			beta = min(beta, bestEval);
			if (alpha >= beta) { break; }
		}
		else
		{
			printf("Invalid Player in Minimax");
			exit(-1);
		}
	}

	*move = bestMove;
	*eval = bestEval;
	return;
}
