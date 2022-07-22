//#include "RowEvalInC.h"
//
//void copyBoard_4x4(Board_4x4* board, Board_4x4 copy)
//{
//	for (int row = 0; row < HEIGHT_4x4; row++)
//	{
//		for (int col = 0; col < WIDTH_4x4; col++)
//		{
//			copy._grid[row][col] = board->_grid[row][col];
//		}
//	}
//}
//
//void copyBoard_7x6(Board_7x6* board, Board_7x6 copy)
//{
//	for (int row = 0; row < HEIGHT_7x6; row++)
//	{
//		for (int col = 0; col < WIDTH_7x6; col++)
//		{
//			copy._grid[row][col] = board->_grid[row][col];
//		}
//	}
//}
//
//void copyBoard_14x12(Board_14x12* board, Board_14x12 copy)
//{
//	for (int row = 0; row < HEIGHT_14x12; row++)
//	{
//		for (int col = 0; col < WIDTH_14x12; col++)
//		{
//			copy._grid[row][col] = board->_grid[row][col];
//		}
//	}
//}
//
//_Bool isValidLoc_4x4(Board_4x4 *board, int col)
//{
//	return board->_grid[0][col] == EMPTY_DISC;
//}
//
//_Bool isValidLoc_7x6(Board_7x6* board, int col)
//{
//	return board->_grid[0][col] == EMPTY_DISC;
//}
//
//_Bool isValidLoc_14x12(Board_14x12* board, int col)
//{
//	return board->_grid[0][col] == EMPTY_DISC;
//}
//
//void minimaxRowEval_4x4(Board_4x4* board, Discs playerDisc)
//{
//	for (int col = 0; col < WIDTH_4x4; col++)
//	{
//		if (!isValidLoc_4x4(board, col)) { continue; }
//
//
//	}
//}