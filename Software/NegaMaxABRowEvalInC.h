#pragma once
#include "DEFINITIONS.hpp" 
#include "RowEvalInC.h"
#include "GameFuncInC.h"
#include <stdlib.h>
#include <limits.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void negamaxABRowEval_4x4(Board_4x4* board, int depth, Discs playerDisc, int alpha, int beta, int* move, int* eval);

	void negamaxABRowEval_7x6(Board_7x6* board, int depth, Discs playerDisc, int alpha, int beta, int* move, int* eval);

	void negamaxABRowEval_14x12(Board_14x12* board, int depth, Discs playerDisc, int alpha, int beta, int* move, int* eval);

#ifdef __cplusplus
}
#endif // __cplusplus
