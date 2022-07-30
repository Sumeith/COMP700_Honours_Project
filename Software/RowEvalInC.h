#pragma once
#include "DEFINITIONS.hpp"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int rowEval_4x4(Board_4x4* board);

	int rowEval_7x6(Board_7x6* board);

	int rowEval_14x12(Board_14x12* board);

	int checkConditionHorizontal(int col, int width);

	int checkConditionVertical(int row, int height);

	int checkConditionPosDiag(int row, int col, int width);

	int checkConditionNegDiag(int row, int col, int height, int width);

	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);

	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);

	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);

#ifdef __cplusplus
}
#endif // __cplusplus