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

	virtual int getEvaluation(Board_4x4* board) = 0;
	virtual int getEvaluation(Board_7x6* board) = 0;
	virtual int getEvaluation(Board_14x12* board) = 0;

	virtual void updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]) = 0;
	virtual void updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]) = 0;
	virtual void updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]) = 0;

	std::string Colour(int colour, std::string message);

	void printBoard(Board_4x4* board);
	void printBoard(Board_7x6* board);
	void printBoard(Board_14x12* board);

	bool checkConditionHorizontal(int col, int width);
	bool checkConditionVertical(int row, int height);
	bool checkConditionPosDiag(int row, int col, int width);
	bool checkConditionNegDiag(int row, int col, int height, int width);
	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);

protected:
	int eval;
};