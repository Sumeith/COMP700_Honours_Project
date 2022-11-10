#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include "DEFINITIONS.hpp"
#include <string>
#include "RowEvalInC.h"
#include "Weight1EvalInC.h"
#include "Weight2EvalInC.h"
#include "Weight3EvalInC.h"
#include "RowWithWeight1Eval.h"
#include "RowWithWeight2Eval.h"
#include "RowWithWeight3Eval.h"
#include <vector>
#include <chrono>

class Player
{
protected:

	std::string playerName;
	int eval;
	int rowEval;
	int weight1Eval;
	int weight2Eval;
	int weight3Eval;
	int rowWeight1Eval;
	int rowWeight2Eval;
	int rowWeight3Eval;

public:
	virtual void nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]) = 0;
	virtual void nextMove(Board_7x4* board, sf::Sprite boardPieces[HEIGHT_7x4][WIDTH_7x4]) = 0;
	virtual void nextMove(Board_4x7* board, sf::Sprite boardPieces[HEIGHT_4x7][WIDTH_4x7]) = 0;
	virtual void nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]) = 0;
	virtual void nextMove(Board_6x7* board, sf::Sprite boardPieces[HEIGHT_6x7][WIDTH_6x7]) = 0;
	virtual void nextMove(Board_8x8* board, sf::Sprite boardPieces[HEIGHT_8x8][WIDTH_8x8]) = 0;
	virtual void nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]) = 0;
	virtual void nextMove(Board_12x14* board, sf::Sprite boardPieces[HEIGHT_12x14][WIDTH_12x14]) = 0;

	virtual void updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]) = 0;
	virtual void updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]) = 0;
	virtual void updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]) = 0;

	int getEvaluation();
	int getRowEvaluation();
	int getWeight1Evaluation();
	int getWeight2Evaluation();
	int getWeight3Evaluation();
	int getRowWeight1Eval();
	int getRowWeight2Eval();
	int getRowWeight3Eval();


	void calcEvaluation_4x4(Board_4x4* board);
	void calcEvaluation_7x4(Board_7x4* board);
	void calcEvaluation_4x7(Board_4x7* board);
	void calcEvaluation_7x6(Board_7x6* board);
	void calcEvaluation_6x7(Board_6x7* board);
	void calcEvaluation_8x8(Board_8x8* board);
	void calcEvaluation_14x12(Board_14x12* board);
	void calcEvaluation_12x14(Board_12x14* board);
};