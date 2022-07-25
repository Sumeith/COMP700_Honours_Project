#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameManager.hpp"
#include "DEFINITIONS.hpp"


class GameState : public State
{
protected:
	//virtual std::string Colour(int colour, std::string message) = 0;
	virtual void InitGridPieces() = 0;
	//virtual void dropDisc() = 0;
	//virtual void printBoard() = 0;
	//virtual int gameEvaluation() = 0;

	std::string Colour(int colour, std::string message);

	void printBoard(Board_4x4* board);
	void printBoard(Board_7x6* board);
	void printBoard(Board_14x12* board);

	bool _gameOver;
	Discs _turn;
	int eval;
};

///////////////////////////////////////////////////////////

class GameState_7x6 : public GameState
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
	/*void dropDisc();
	void printBoard();
	std::string Colour(int colour, std::string message);*/
	void checkWinner();
	/*int gameEvaluation();
	bool checkConditionHorizontal(int col);
	bool checkConditionVertical(int row);
	bool checkConditionPosDiag(int row, int col);
	bool checkConditionNegDiag(int row, int col);
	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);*/

	const int _height = HEIGHT_7x6;
	const int _width = WIDTH_7x6;
	const int totalDiscs = HEIGHT_7x6 * WIDTH_7x6;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_7x6][WIDTH_7x6];
};

/////////////////////////////////////////////////////////

class GameState_4x4 : public GameState
{
public:
	GameState_4x4(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_4x4 _board;

	void InitGridPieces();
	//void dropDisc();
	/*void printBoard();
	std::string Colour(int colour, std::string message);*/
	void checkWinner();
	/*int gameEvaluation();
	bool checkConditionHorizontal(int col);
	bool checkConditionVertical(int row);
	bool checkConditionPosDiag(int row, int col);
	bool checkConditionNegDiag(int row, int col);
	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);*/

	const int _height = HEIGHT_4x4;
	const int _width = WIDTH_4x4;
	const int totalDiscs = HEIGHT_4x4 * WIDTH_4x4;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_4x4][WIDTH_4x4];
};

/////////////////////////////////////////////////////////

class GameState_14x12 : public GameState
{
public:
	GameState_14x12(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_14x12 _board;

	void InitGridPieces();
	/*void dropDisc();
	void printBoard();
	std::string Colour(int colour, std::string message);*/
	void checkWinner();
	/*int gameEvaluation();
	bool checkConditionHorizontal(int col);
	bool checkConditionVertical(int row);
	bool checkConditionPosDiag(int row, int col);
	bool checkConditionNegDiag(int row, int col);
	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);*/

	const int _height = HEIGHT_14x12;
	const int _width = WIDTH_14x12;
	const int totalDiscs = HEIGHT_14x12 * WIDTH_14x12;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_14x12][WIDTH_14x12];
};

/////////////////////////////////////////////////////////

//class GameState_21x18 : public GameState
//{
//public:
//	GameState_21x18(GameDataRef data);
//	void Init();
//	void HandleInput();
//	void Update(float dt);
//	void Draw(float dt);
//
//private:
//	GameDataRef _data;
//	sf::Sprite _background;
//	sf::Clock _clock;
//	Board_7x6 _board;
//
//	void InitGridPieces();
//	void dropDisc();
//	void printBoard();
//	std::string Colour(int colour, std::string message);
//	void checkWinner();
//	int gameEvaluation();
//	bool checkConditionHorizontal(int col);
//	bool checkConditionVertical(int row);
//	bool checkConditionPosDiag(int row, int col);
//	bool checkConditionNegDiag(int row, int col);
//	void checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
//	void checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
//	void checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[]);
//
//	const int _height = HEIGHT_21x18;
//	const int _width = WIDTH_21x18;
//	sf::Sprite _boardPieces[HEIGHT_21x18][WIDTH_21x18];
//	bool _gameOver;
//	Discs _turn;
//};