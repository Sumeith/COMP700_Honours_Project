#pragma once
#include "DEFINITIONS.hpp" 
#include <stdbool.h>
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

	void Dripdisc_4x4(Board_4x4* board, int column, Discs playerDisc);
	void Dripdisc_7x4(Board_7x4* board, int column, Discs playerDisc);
	void Dripdisc_4x7(Board_4x7* board, int column, Discs playerDisc);
	void Dripdisc_7x6(Board_7x6* board, int column, Discs playerDisc);
	void Dripdisc_6x7(Board_6x7* board, int column, Discs playerDisc);
	void Dripdisc_8x8(Board_8x8* board, int column, Discs playerDisc);
	void Dripdisc_14x12(Board_14x12* board, int column, Discs playerDisc);
	void Dripdisc_12x14(Board_12x14* board, int column, Discs playerDisc);

	void copyBoard_4x4(Board_4x4* board, Board_4x4* copy);
	void copyBoard_7x4(Board_7x4* board, Board_7x4* copy);
	void copyBoard_4x7(Board_4x7* board, Board_4x7* copy);
	void copyBoard_7x6(Board_7x6* board, Board_7x6* copy);
	void copyBoard_6x7(Board_6x7* board, Board_6x7* copy);
	void copyBoard_8x8(Board_8x8* board, Board_8x8* copy);
	void copyBoard_14x12(Board_14x12* board, Board_14x12* copy);
	void copyBoard_12x14(Board_12x14* board, Board_12x14* copy);

	bool isValidLoc_4x4(Board_4x4* board, int col);
	bool isValidLoc_7x4(Board_7x4* board, int col);
	bool isValidLoc_4x7(Board_4x7* board, int col);
	bool isValidLoc_7x6(Board_7x6* board, int col);
	bool isValidLoc_6x7(Board_6x7* board, int col);
	bool isValidLoc_8x8(Board_8x8* board, int col);
	bool isValidLoc_14x12(Board_14x12* board, int col);
	bool isValidLoc_12x14(Board_12x14* board, int col);

	bool isGameOver_4x4(Board_4x4* board);
	bool isGameOver_7x4(Board_7x4* board);
	bool isGameOver_4x7(Board_4x7* board);
	bool isGameOver_7x6(Board_7x6* board);
	bool isGameOver_6x7(Board_6x7* board);
	bool isGameOver_8x8(Board_8x8* board);
	bool isGameOver_14x12(Board_14x12* board);
	bool isGameOver_12x14(Board_12x14* board);
#ifdef __cplusplus
}
#endif // __cplusplus