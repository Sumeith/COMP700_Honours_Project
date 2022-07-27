//#include "NegaMaxRowEvalInC.h"
//
//void negamaxRowEval_4x4(Board_4x4* board, int depth, Discs playerDisc, int* move, int* eval)
//{
//
//}
//
//void negamaxRowEval_7x6(Board_7x6* board, int depth, Discs playerDisc, int* move, int *eval)
//{
//	int bestEval = INT_MIN;
//	int bestMove = -1;
//
//	for (int col = 0; col < WIDTH_7x6; col++)
//	{
//		if (!isValidLoc_7x6(board, col)) { continue; }
//
//		Board_7x6 tempboard;
//		Dripdisc_7x6(&tempboard, col, playerDisc);
//		int tempEval = rowEval_7x6(&tempboard);
//		
//		if (playerDisc == PLAYER_ONE_DISC && tempEval == PLAYER_ONE_WINS)
//		{
//			bestMove = col;
//			bestEval = tempEval;
//			break;
//		}
//
//		int inMove;
//		int inEval;
//		if (depth > 1)
//		{
//			negamaxRowEval_7x6(board,
//				depth - 1, 
//				playerDisc == PLAYER_ONE_DISC ? PLAYER_TWO_DISC : PLAYER_ONE_DISC, 
//				&inMove,
//				&inEval);
//		}
//		else
//		{
//			inMove = -1;
//			inEval = eval;
//		}
//
//		if (inEval > bestEval)
//		{
//			bestEval = inEval;
//			bestMove = col;
//		}
//	}
//	*move = bestMove;
//	*eval = bestEval * -1;
//}
//
//void negamaxRowEval_14x12(Board_14x12* board, int depth, Discs playerDisc, int* move, int* eval)
//{
//
//}