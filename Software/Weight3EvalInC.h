#pragma once
#include "DEFINITIONS.hpp"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int weight3Eval_4x4(Board_4x4* board);

	int weight3Eval_7x4(Board_7x4* board);

	int weight3Eval_4x7(Board_4x7* board);

	int weight3Eval_7x6(Board_7x6* board);

	int weight3Eval_6x7(Board_6x7* board);

	int weight3Eval_8x8(Board_8x8* board);

	int weight3Eval_14x12(Board_14x12* board);

	int weight3Eval_12x14(Board_12x14* board);

#ifdef __cplusplus
}
#endif // __cplusplus