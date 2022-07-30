#pragma once
#include "DEFINITIONS.hpp"
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int rowWeight2Eval_4x4(Board_4x4* board);

	int rowWeight2_7x6(Board_7x6* board);

	int rowWeight2_14x12(Board_14x12* board);

#ifdef __cplusplus
}
#endif // __cplusplus