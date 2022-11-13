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
#include <numeric>
class Player
{
protected:
	int eval;
	int rowEval;
	int weight1Eval;
	int weight2Eval;
	int weight3Eval;
	int rowWeight1Eval;
	int rowWeight2Eval;
	int rowWeight3Eval;
	
	std::vector<long long> timeVector;

	std::vector<int> rowEvalVector;
	std::vector<int> weight1EvalVector;
	std::vector<int> weight2EvalVector;
	std::vector<int> weight3EvalVector;
	std::vector<int> rowWeight1EvalVector;
	std::vector<int> rowWeight2EvalVector;
	std::vector<int> rowWeight3EvalVector;

	std::vector<int> rowEvalDiff;
	std::vector<int> weight1EvalDiff;
	std::vector<int> weight2EvalDiff;
	std::vector<int> weight3EvalDiff;
	std::vector<int> rowWeight1EvalDiff;
	std::vector<int> rowWeight2EvalDiff;
	std::vector<int> rowWeight3EvalDiff;

public:
	std::string playerName;
	int result{ 0 };
	int firstColumn{ -1 };

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

	long long getAverageTime();
	double getAverageRowEval();
	double getAverageWeight1Eval();
	double getAverageWeight2Eval();
	double getAverageWeight3Eval();
	double getAverageRowWeight1Eval();
	double getAverageRowWeight2Eval();
	double getAverageRowWeight3Eval();

	long long getMaxTime();
	int getMaxRowEval();
	int getMaxWeight1Eval();
	int getMaxWeight2Eval();
	int getMaxWeight3Eval();
	int getMaxRowWeight1Eval();
	int getMaxRowWeight2Eval();
	int getMaxRowWeight3Eval();

	long long getMinTime();
	int getMinRowEval();
	int getMinWeight1Eval();
	int getMinWeight2Eval();
	int getMinWeight3Eval();
	int getMinRowWeight1Eval();
	int getMinRowWeight2Eval();
	int getMinRowWeight3Eval();

	double getAverageRowEvalDiff();
	double getAverageWeight1EvalDiff();
	double getAverageWeight2EvalDiff();
	double getAverageWeight3EvalDiff();
	double getAverageRowWeight1EvalDiff();
	double getAverageRowWeight2EvalDiff();
	double getAverageRowWeight3EvalDiff();

	
	double getMaxRowEvalDiff();
	double getMaxWeight1EvalDiff();
	double getMaxWeight2EvalDiff();
	double getMaxWeight3EvalDiff();
	double getMaxRowWeight1EvalDiff();
	double getMaxRowWeight2EvalDiff();
	double getMaxRowWeight3EvalDiff();

	
	double getMinRowEvalDiff();
	double getMinWeight1EvalDiff();
	double getMinWeight2EvalDiff();
	double getMinWeight3EvalDiff();
	double getMinRowWeight1EvalDiff();
	double getMinRowWeight2EvalDiff();
	double getMinRowWeight3EvalDiff();

	void displayResult();
};