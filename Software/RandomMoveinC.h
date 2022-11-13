#pragma once
#include "DEFINITIONS.hpp" 
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getRandomColumn_4x4(Board_4x4 *board);
	int getRandomColumn_7x4(Board_7x4* board);
	int getRandomColumn_4x7(Board_4x7* board);
	int getRandomColumn_7x6(Board_7x6 *board);
	int getRandomColumn_6x7(Board_6x7* board);
	int getRandomColumn_8x8(Board_8x8* board);
	int getRandomColumn_14x12(Board_14x12 *board);
	int getRandomColumn_12x14(Board_12x14* board);

#ifdef __cplusplus
}
#endif // __cplusplus
