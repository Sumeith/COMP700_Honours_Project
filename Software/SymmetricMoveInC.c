//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
//#include <time.h>
//#include "SymmetricMoveinC.h"
//
//int getSymmetricColumn_4x4(Board_4x4* board, int prevCol)
//{
//	//if statement to determine if the prevColomn is invalid
//	if (prevCol < 0 || prevCol >= WIDTH_4x4)
//	{
//		return getRandomprevColumn_4x4(board);
//	}
//	int prevColPlacement = prevCol % WIDTH_4x4;
//	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
//	{
//		return prevColPlacement;
//	}
//	else
//	{
//		return getRandomprevColumn_4x4(board);
//	}
//}
//
//int getSymmetricColumn_7x6(Board_7x6* board, int prevCol)
//{
//	//if statement to determine if the prevColomn is invalid
//	if (prevCol < 0 || prevCol >= WIDTH_4x4)
//	{
//		return getRandomprevColumn_4x4(board);
//	}
//	int prevColPlacement = prevCol % WIDTH_4x4;
//	if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
//	{
//		return prevColPlacement;
//	}
//	else
//	{
//		return getRandomprevColumn_4x4(board);
//	}
//}
//
//int getSymmetricColumn_14x12(Board_14x12* board, int prevCol)
//{
//	bool foundprevColumn = false;
//	int prevColPlacement;
//	srand(time(0));
//	while (!foundprevColumn)
//	{
//		prevColPlacement = rand() % (WIDTH_14x12 + 1);
//		if (board->_grid[0][prevColPlacement] == EMPTY_DISC)
//		{
//			foundprevColumn = true;
//		}
//	}
//	return prevColPlacement;
//}