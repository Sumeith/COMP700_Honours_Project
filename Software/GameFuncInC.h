#pragma once
#include "DEFINITIONS.hpp" 
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void Dripdisc_4x4(Board_4x4* board, int column, Discs playerDisc);

	void Dripdisc_7x6(Board_7x6* board, int column, Discs playerDisc);
	
	void Dripdisc_14x12(Board_14x12* board, int column, Discs playerDisc);

	void copyBoard_4x4(Board_4x4* board, Board_4x4* copy);

	void copyBoard_7x6(Board_7x6* board, Board_7x6* copy);

	void copyBoard_14x12(Board_14x12* board, Board_14x12* copy);

	bool isValidLoc_4x4(Board_4x4* board, int col);

	bool isValidLoc_7x6(Board_7x6* board, int col);
	
	bool isValidLoc_14x12(Board_14x12* board, int col);

	bool isGameOver_4x4(Board_4x4* board);

	bool isGameOver_7x6(Board_7x6* board);
	
	bool isGameOver_14x12(Board_14x12* board);
#ifdef __cplusplus
}
#endif // __cplusplus