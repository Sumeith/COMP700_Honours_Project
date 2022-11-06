#pragma once
#include "DEFINITIONS.hpp" 
#include <stdbool.h>
#include "stdio.h"
#include "omp.h"
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void Dripdisc_openMP_4x4(Board_4x4* board, int column, Discs playerDisc);

	void Dripdisc_openMP_7x6(Board_7x6* board, int column, Discs playerDisc);

	void Dripdisc_openMP_14x12(Board_14x12* board, int column, Discs playerDisc);

	void copyBoard_openMP_4x4(Board_4x4* board, Board_4x4* copy);

	void copyBoard_openMP_7x6(Board_7x6* board, Board_7x6* copy);

	void copyBoard_openMP_14x12(Board_14x12* board, Board_14x12* copy);

	bool isValidLoc_openMP_4x4(Board_4x4* board, int col);

	bool isValidLoc_openMP_7x6(Board_7x6* board, int col);

	bool isValidLoc_openMP_14x12(Board_14x12* board, int col);

	bool isGameOver_openMP_4x4(Board_4x4* board);

	bool isGameOver_openMP_7x6(Board_7x6* board);

	bool isGameOver_openMP_14x12(Board_14x12* board);
#ifdef __cplusplus
}
#endif // __cplusplus