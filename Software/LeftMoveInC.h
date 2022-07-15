#pragma once
#include "DEFINITIONS.hpp" 
#include "RandomMoveinC.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	int getLeftColumn_4x4(Board_4x4* board, int prevCol);

	int getLeftColumn_7x6(Board_7x6* board, int prevCol);

	int getLeftColumn_14x12(Board_14x12* board, int prevCol);

#ifdef __cplusplus
}
#endif // __cplusplus
