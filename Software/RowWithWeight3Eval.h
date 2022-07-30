#pragma once
#include "DEFINITIONS.hpp"
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int rowWeight3Eval_4x4(Board_4x4* board);

	int rowWeight3_7x6(Board_7x6* board);

	int rowWeight3_14x12(Board_14x12* board);

#ifdef __cplusplus
}
#endif // __cplusplus