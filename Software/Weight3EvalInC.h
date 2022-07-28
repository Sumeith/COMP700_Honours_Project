#pragma once
#include "DEFINITIONS.hpp"
#include "HeuristicsWeights.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int weight3Eval_4x4(Board_4x4* board);

	int weight3Eval_7x6(Board_7x6* board);

	int weight3Eval_14x12(Board_14x12* board);

#ifdef __cplusplus
}
#endif // __cplusplus