#pragma once
#include "DEFINITIONS.hpp"
#include <limits.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int rowWeight2_4x4(Board_4x4* board);

	int rowWeight2_7x4(Board_7x4* board);

	int rowWeight2_4x7(Board_4x7* board);

	int rowWeight2_7x6(Board_7x6* board);

	int rowWeight2_6x7(Board_6x7* board);

	int rowWeight2_8x8(Board_8x8* board);

	int rowWeight2_14x12(Board_14x12* board);

	int rowWeight2_12x14(Board_12x14* board);

#ifdef __cplusplus
}
#endif // __cplusplus