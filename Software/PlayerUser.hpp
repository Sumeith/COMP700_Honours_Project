#pragma once

#include "DEFINITIONS.hpp"
#include "Player.hpp"
#include "GameManager.hpp"

class PlayerUser : public Player
{
public:
	PlayerUser(GameDataRef data, Discs playerDisc);

	void nextMove(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]);
	void nextMove(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]);
	void nextMove(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]);

	int getEvaluation(Board_4x4* board);
	int getEvaluation(Board_7x6* board);
	int getEvaluation(Board_14x12* board);

	void updateGameState(Board_4x4* board, sf::Sprite boardPieces[HEIGHT_4x4][WIDTH_4x4]);
	void updateGameState(Board_7x6* board, sf::Sprite boardPieces[HEIGHT_7x6][WIDTH_7x6]);
	void updateGameState(Board_14x12* board, sf::Sprite boardPieces[HEIGHT_14x12][WIDTH_14x12]);

private:
	GameDataRef _data;
	Discs _playerDisc;
};