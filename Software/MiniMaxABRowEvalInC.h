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

	int minimaxABRowEval_4x4(Board_4x4* board, int depth, int alpha, int beta, Discs playerDisc, int* move);

	int minimaxABRowEval_7x6(Board_7x6* board, int depth, int alpha, int beta, Discs playerDisc, int* move);

	int minimaxABRowEval_14x12(Board_14x12* board, int depth, int alpha, int beta, Discs playerDisc, int* move);

#ifdef __cplusplus
}
#endif // __cplusplus
