#include "minimaxABRowEvalInC.h"

void minimaxABRowEval_4x4(Board_4x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_4x4(board) ||
		depth == 0)
	{
		*eval = rowEval_4x4(board);
		return;
	}

	int bestEval = playerDisc == PLAYER_ONE_DISC ? INT_MIN : INT_MAX;
	int bestMove = NULL;

	for (int col = 0; col < WIDTH_4x4; col++)
	{

		if (!isValidLoc_4x4(board, col)) { continue; }

		Board_14x12 tempBoard;
		int tempMove;
		int tempEval;
		copyBoard_4x4(board, &tempBoard);

		//Maximizing Player
		if (playerDisc == PLAYER_ONE_DISC)
		{
			Dripdisc_4x4(&tempBoard, col, PLAYER_ONE_DISC);
			minimaxABRowEval_4x4(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
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
			minimaxABRowEval_4x4(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
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

void minimaxABRowEval_7x6(Board_7x6* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_7x6(board) ||
		depth == 0)
	{
		*eval = rowEval_7x6(board);
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
			minimaxABRowEval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
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
			minimaxABRowEval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
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

void minimaxABRowEval_14x12(Board_14x12* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval)
{
	if (isGameOver_14x12(board) ||
		depth == 0)
	{
		*eval = rowEval_14x12(board);
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
			minimaxABRowEval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, &tempMove, &tempEval);
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
			minimaxABRowEval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, &tempMove, &tempEval);
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

//int minimaxABRowEval_4x4(Board_4x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move)
//{
//	int boardEval = rowEval_4x4(board);
//	if (boardEval == INT_MAX || 
//		boardEval == INT_MIN || depth == 0)
//	{
//		return boardEval;
//	}
//	int bestEval = boardEval;
//	int tempEval;
//	int bestMove = *move;
//	//Maximizing Player
//	if (playerDisc == PLAYER_ONE_DISC)
//	{
//		bestEval = INT_MIN;
//		for (int col = 0; col < WIDTH_4x4; col++)
//		{
//
//			if (!isValidLoc_4x4(board, col)) { continue; }
//
//			Board_4x4 tempBoard;
//			copyBoard_4x4(board, &tempBoard);
//			Dripdisc_4x4(&tempBoard, col, PLAYER_ONE_DISC);
//			tempEval = minimaxABRowEval_4x4(&tempBoard, depth -1, alpha, beta, PLAYER_TWO_DISC, &bestMove);
//			if (tempEval > bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
			/*alpha = max(alpha, bestEval);
			if (alpha >= beta) { break; }*/
//		}
//	}
//
//	//Minimizing Player
//	if (playerDisc == PLAYER_TWO_DISC)
//	{
//		bestEval = INT_MAX;
//		for (int col = 0; col < WIDTH_4x4; col++)
//		{
//			if (!isValidLoc_4x4(board, col)) { continue; }
//
//			Board_4x4 tempBoard;
//			copyBoard_4x4(board, &tempBoard);
//			Dripdisc_4x4(&tempBoard, col, PLAYER_TWO_DISC);
//			tempEval = minimaxABRowEval_4x4(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, move);
//			bestMove = col;
//
//			if (tempEval < bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
			//beta = min(beta, bestEval);
			//if (alpha >= beta) { break; }
//		}
//	}
//
//	*move = bestMove;
//	return bestEval;
//}
//
//int minimaxABRowEval_7x6(Board_7x6* board, int depth, int alpha, int beta, Discs playerDisc, int* move)
//{
//	int boardEval = rowEval_7x6(board);
//	if (boardEval == INT_MAX ||
//		boardEval == INT_MIN || depth == 0)
//	{
//		return boardEval;
//	}
//	int bestEval = boardEval;
//	int tempEval;
//	int bestMove = 0;
//	//Maximizing Player
//	if (playerDisc == PLAYER_ONE_DISC)
//	{
//		bestEval = INT_MIN;
//		for (int col = 0; col < WIDTH_7x6; col++)
//		{
//
//			if (!isValidLoc_7x6(board, col)) { continue; }
//
//			Board_7x6 tempBoard;
//			copyBoard_7x6(board, &tempBoard);
//			Dripdisc_7x6(&tempBoard, col, PLAYER_ONE_DISC);
//			tempEval = minimaxABRowEval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, move);
//			if (tempEval > bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
//			alpha = max(alpha, bestEval);
//			if (alpha >= beta) { break; }
//		}
//	}
//
//	//Minimizing Player
//	if (playerDisc == PLAYER_TWO_DISC)
//	{
//		bestEval = INT_MAX;
//		for (int col = 0; col < WIDTH_7x6; col++)
//		{
//			if (!isValidLoc_7x6(board, col)) { continue; }
//
//			Board_7x6 tempBoard;
//			copyBoard_7x6(board, &tempBoard);
//			Dripdisc_7x6(&tempBoard, col, PLAYER_TWO_DISC);
//			tempEval = minimaxABRowEval_7x6(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, move);
//
//			if (tempEval < bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
//			beta = min(beta, bestEval);
//			if (alpha >= beta) { break; }
//		}
//	}
//
//	*move = bestMove;
//	return bestEval;
//}
//
//int minimaxABRowEval_14x12(Board_14x12* board, int depth, int alpha, int beta, Discs playerDisc, int* move)
//{
//	int boardEval = rowEval_14x12(board);
//	if (boardEval == INT_MAX ||
//		boardEval == INT_MIN || depth == 0)
//	{
//		return boardEval;
//	}
//	int bestEval = boardEval;
//	int tempEval;
//	int bestMove = *move;
//	//Maximizing Player
//	if (playerDisc == PLAYER_ONE_DISC)
//	{
//		bestEval = INT_MIN;
//		for (int col = 0; col < WIDTH_14x12; col++)
//		{
//
//			if (!isValidLoc_14x12(board, col)) { continue; }
//
//			Board_14x12 tempBoard;
//			copyBoard_14x12(board, &tempBoard);
//			Dripdisc_14x12(&tempBoard, col, PLAYER_ONE_DISC);
//			tempEval = minimaxABRowEval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_TWO_DISC, move);
//			if (tempEval > bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
//			alpha = max(alpha, bestEval);
//			if (alpha >= beta) { break; }
//		}
//	}
//
//	//Minimizing Player
//	if (playerDisc == PLAYER_TWO_DISC)
//	{
//		bestEval = INT_MAX;
//		for (int col = 0; col < WIDTH_14x12; col++)
//		{
//			if (!isValidLoc_14x12(board, col)) { continue; }
//
//			Board_14x12 tempBoard;
//			copyBoard_14x12(board, &tempBoard);
//			Dripdisc_14x12(&tempBoard, col, PLAYER_TWO_DISC);
//			tempEval = minimaxABRowEval_14x12(&tempBoard, depth - 1, alpha, beta, PLAYER_ONE_DISC, move);
//			bestMove = col;
//
//			if (tempEval < bestEval)
//			{
//				bestMove = col;
//				bestEval = tempEval;
//			}
//			beta = min(beta, bestEval);
//			if (alpha >= beta) { break; }
//		}
//	}
//
//	*move = bestMove;
//	return bestEval;
//}