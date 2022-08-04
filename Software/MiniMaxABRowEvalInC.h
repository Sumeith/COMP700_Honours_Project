#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "DEFINITIONS.hpp" 
#include "RowEvalInC.h"
#include "GameFuncInC.h"
#include <limits.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void minimaxABRowEval_4x4(Board_4x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval);

	void minimaxABRowEval_7x6(Board_7x6* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval);

	void minimaxABRowEval_14x12(Board_14x12* board, int depth, int alpha, int beta, Discs playerDisc, int* move, int* eval);

#ifdef __cplusplus
}
#endif // __cplusplus
