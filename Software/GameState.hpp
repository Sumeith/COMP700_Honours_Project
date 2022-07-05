#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameManager.hpp"
#include "DEFINITIONS.hpp"


class GameState
{
private:
	virtual std::string Colour(int colour, std::string message) = 0;
	virtual void InitGridPieces() = 0;
	virtual void dropDisc() = 0;
	virtual void printBoard() = 0;
	virtual int gameEvaluation() = 0;
};

///////////////////////////////////////////////////////////

class GameState_7x6 : public GameState, public State
{
public:
	GameState_7x6(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_7x6 _board;

	void InitGridPieces();
	void dropDisc();
	void printBoard();
	std::string Colour(int colour, std::string message);
	void checkWinner();
	int gameEvaluation();

	const int _height = HEIGHT_7x6;
	const int _width = WIDTH_7x6;
	sf::Sprite _boardPieces[HEIGHT_7x6][WIDTH_7x6];
	bool _gameOver;
	Discs _turn;
};

///////////////////////////////////////////////////////////
//
//class GameState_4x4 : public GameState, public State
//{
//public:
//	GameState_4x4(GameDataRef data);
//	void Init();
//	void HandleInput();
//	void Update(float dt);
//	void Draw(float dt);
//	std::string Colour(int colour, std::string message);
//private:
//	GameDataRef _data;
//	sf::Sprite _background;
//	sf::Clock _clock;
//	Board_4x4 _board;
//
//	void InitGridPieces();
//	void CheckAndPlacePiece();
//	void printBoard();
//	int gameEvaluation();
//	const int _height = 4;
//	const int _width = 4;
//	sf::Sprite _boardPieces[4][4];
//	Discs _turn;
//	int gameState;
//};
//
/////////////////////////////////////////////////////////////
//
//class GameState_21x18 : public GameState, public State
//{
//public:
//	GameState_21x18(GameDataRef data);
//	void Init();
//	void HandleInput();
//	void Update(float dt);
//	void Draw(float dt);
//	std::string Colour(int colour, std::string message);
//private:
//	GameDataRef _data;
//	sf::Sprite _background;
//	sf::Clock _clock;
//	Board_21x18 _board;
//
//	void InitGridPieces();
//	void CheckAndPlacePiece();
//	void printBoard();
//	int gameEvaluation();
//	const int _height = 18;
//	const int _width = 21;
//	sf::Sprite _boardPieces[18][21];
//	Discs _turn;
//	int gameState;
//};