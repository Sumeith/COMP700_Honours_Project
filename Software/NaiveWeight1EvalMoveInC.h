#pragma once
#include "DEFINITIONS.hpp" 
#include "GameFuncInC.h"
#include "Weight1EvalInC.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getNaiveWeight1EvalColumn_4x4(Board_4x4* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_7x4(Board_7x4* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_4x7(Board_4x7* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_7x6(Board_7x6* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_6x7(Board_6x7* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_8x8(Board_8x8* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_14x12(Board_14x12* board, Discs playerDisc);
	int getNaiveWeight1EvalColumn_12x14(Board_12x14* board, Discs playerDisc);

#ifdef __cplusplus
}
#endif // __cplusplus
