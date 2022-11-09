#pragma once
#include <stdbool.h>
#include <stdio.h>
#include "DEFINITIONS.hpp" 
#include "Weight2EvalInC.h"
#include "GameFuncInC.h"
#include <limits.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void minimaxWeight2Eval_4x4(Board_4x4* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_7x4(Board_7x4* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_4x7(Board_4x7* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_7x6(Board_7x6* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_6x7(Board_6x7* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_8x8(Board_8x8* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_14x12(Board_14x12* board, int depth, Discs playerDisc, int* move, int* eval);
	void minimaxWeight2Eval_12x14(Board_12x14* board, int depth, Discs playerDisc, int* move, int* eval);

#ifdef __cplusplus
}
#endif // __cplusplus
