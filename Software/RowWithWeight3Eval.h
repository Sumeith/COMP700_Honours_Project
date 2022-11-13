#pragma once
#include "DEFINITIONS.hpp"
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int rowWeight3_4x4(Board_4x4* board);

	int rowWeight3_7x4(Board_7x4* board);

	int rowWeight3_4x7(Board_4x7* board);

	int rowWeight3_7x6(Board_7x6* board);

	int rowWeight3_6x7(Board_6x7* board);

	int rowWeight3_8x8(Board_8x8* board);

	int rowWeight3_14x12(Board_14x12* board);

	int rowWeight3_12x14(Board_12x14* board);

#ifdef __cplusplus
}
#endif // __cplusplus