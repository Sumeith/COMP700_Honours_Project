#pragma once

#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameManager.hpp"
#include "DEFINITIONS.hpp"
#include <fstream>
#include <string.h>
class GameState : public State
{
protected:
	virtual void InitGridPieces() = 0;
	bool reported = false;
	std::string Colour(int colour, std::string message);
	void printBoard(Board_4x4* board);
	void printBoard(Board_7x4* board);
	void printBoard(Board_4x7* board);
	void printBoard(Board_7x6* board);
	void printBoard(Board_6x7* board);
	void printBoard(Board_8x8* board);
	void printBoard(Board_14x12* board);
	void printBoard(Board_12x14* board);

	bool _gameOver;
	Discs _turn;
	int eval;
};

///////////////////////////////////////////////////////////

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
	void checkWinner();
	
	const int _height = HEIGHT_4x4;
	const int _width = WIDTH_4x4;
	const int totalDiscs = HEIGHT_4x4 * WIDTH_4x4;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_4x4][WIDTH_4x4];
};

///////////////////////////////////////////////////////////

class GameState_7x4 : public GameState
{
public:
	GameState_7x4(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_7x4 _board;

	void InitGridPieces();
	void checkWinner();

	const int _height = HEIGHT_7x4;
	const int _width = WIDTH_7x4;
	const int totalDiscs = HEIGHT_7x4 * WIDTH_7x4;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_7x4][WIDTH_7x4];
};

///////////////////////////////////////////////////////////

class GameState_4x7 : public GameState
{
public:
	GameState_4x7(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_4x7 _board;

	void InitGridPieces();
	void checkWinner();

	const int _height = HEIGHT_4x7;
	const int _width = WIDTH_4x7;
	const int totalDiscs = HEIGHT_4x7 * WIDTH_4x7;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_4x7][WIDTH_4x7];
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
	void checkWinner();

	const int _height = HEIGHT_7x6;
	const int _width = WIDTH_7x6;
	const int totalDiscs = HEIGHT_7x6 * WIDTH_7x6;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_7x6][WIDTH_7x6];
};

///////////////////////////////////////////////////////////

class GameState_6x7 : public GameState
{
public:
	GameState_6x7(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_6x7 _board;

	void InitGridPieces();
	void checkWinner();

	const int _height = HEIGHT_6x7;
	const int _width = WIDTH_6x7;
	const int totalDiscs = HEIGHT_6x7 * WIDTH_6x7;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_6x7][WIDTH_6x7];
};

/////////////////////////////////////////////////////////


class GameState_8x8 : public GameState
{
public:
	GameState_8x8(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_8x8 _board;

	void InitGridPieces();
	void checkWinner();
	
	const int _height = HEIGHT_8x8;
	const int _width = WIDTH_8x8;
	const int totalDiscs = HEIGHT_8x8 * WIDTH_8x8;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_8x8][WIDTH_8x8];
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
	void checkWinner();
	
	const int _height = HEIGHT_14x12;
	const int _width = WIDTH_14x12;
	const int totalDiscs = HEIGHT_14x12 * WIDTH_14x12;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_14x12][WIDTH_14x12];
};

/////////////////////////////////////////////////////////

class GameState_12x14 : public GameState
{
public:
	GameState_12x14(GameDataRef data);
	void Init();
	void HandleInput();
	void Update(float dt);
	void Draw(float dt);

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Clock _clock;
	Board_12x14 _board;

	void InitGridPieces();
	void checkWinner();

	const int _height = HEIGHT_12x14;
	const int _width = WIDTH_12x14;
	const int totalDiscs = HEIGHT_12x14 * WIDTH_12x14;
	int numDiscs = 0;
	sf::Sprite _boardPieces[HEIGHT_12x14][WIDTH_12x14];
};