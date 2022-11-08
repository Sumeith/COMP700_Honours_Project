#pragma once
#include "DEFINITIONS.hpp" 
#include "RandomMoveinC.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getRightColumn_4x4(Board_4x4* board, int prevCol);
	int getRightColumn_7x4(Board_7x4* board, int prevCol);
	int getRightColumn_4x7(Board_4x7* board, int prevCol);
	int getRightColumn_7x6(Board_7x6* board, int prevCol);
	int getRightColumn_6x7(Board_6x7* board, int prevCol);
	int getRightColumn_8x8(Board_8x8* board, int prevCol);
	int getRightColumn_14x12(Board_14x12* board, int prevCol);
	int getRightColumn_12x14(Board_12x14* board, int prevCol);

#ifdef __cplusplus
}
#endif // __cplusplus
