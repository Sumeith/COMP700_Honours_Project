#pragma once
#include "DEFINITIONS.hpp" 
#include "GameFuncInC.h"
#include "RowEvalInC.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getNaiveRowEvalColumn_4x4(Board_4x4* board, Discs playerDisc);

	int getNaiveRowEvalColumn_7x6(Board_7x6* board, Discs playerDisc);

	int getNaiveRowEvalColumn_14x12(Board_14x12* board, Discs playerDisc);

#ifdef __cplusplus
}
#endif // __cplusplus
