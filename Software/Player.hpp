#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

#include "DEFINITIONS.hpp"

class Player
{
public:
	virtual void nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]) = 0;
	virtual void nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]) = 0;
	virtual void nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]) = 0;

	virtual int calcEvaluation(Board_4x4* board) = 0;
	virtual int calcEvaluation(Board_7x6* board) = 0;
	virtual int calcEvaluation(Board_14x12* board) = 0;

	virtual void updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]) = 0;
	virtual void updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]) = 0;
	virtual void updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]) = 0;

	int getEvaluation();
	int getRowEvaluation();
	int getWeight1Evaluation();
	int getWeight2Evaluation();
	int getWeight3Evaluation();

protected:
	int eval;
	int rowEval;
	int weight1Eval;
	int weight2Eval;
	int weight3Eval;
};