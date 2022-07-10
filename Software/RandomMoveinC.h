#pragma once
#include "DEFINITIONS.hpp" 
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getRandomColumn_4x4(Board_4x4 *board);

	int getRandomColumn_7x6(Board_7x6 *board);

	int getRandomColumn_14x12(Board_14x12 *board);

#ifdef __cplusplus
}
#endif // __cplusplus
