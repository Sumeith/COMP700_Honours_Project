//#include <sstream>
//#include <iostream>
//#include "GameState.hpp"
//#include "DEFINITIONS.hpp"
//#include "GameMenuState.hpp"
//#include <iostream>
//#include <windows.h>
//#include <string>
//#include <cassert>
//
//GameState_4x4::GameState_4x4(GameDataRef data) : _data(data)
//{
//
//}
//
//void GameState_4x4::Init()
//{
//	_turn = PLAYER_ONE_DISC;
//	gameState = IN_PROGRESS;
//
//	this->_data->assets.LoadTexture("Game BOARD", GAME_BOARD_PATH);
//
//	this->_data->assets.LoadTexture("Player One Disc", PLAYER_ONE_DISC_PATH);
//	this->_data->assets.LoadTexture("Player Two Disc", PLAYER_TWO_DISC_PATH);
//	this->_data->assets.LoadTexture("Empty Disc", EMPTY_DISC_PATH);
//	this->_data->assets.LoadTexture("Game Board", GAME_BOARD_PATH);
//
//	this -> _data-> window.create(sf::VideoMode(400, 400), "Connet 4 on a 4x4 board", sf::Style::Close | sf::Style::Titlebar);
//
//	this->_background.setTexture(this->_data->assets.GetTexture("Game BOARD"));
//	
//	for (int x = 0; x < _height; x++)
//	{
//		for (int y = 0; y < _width; y++)
//		{
//			_board._grid[x][y] = EMPTY_DISC;
//		}
//	}
//
//	InitGridPieces();
//}
//
//void GameState_4x4::InitGridPieces()
//{
//	sf::Vector2u tempDiscSize = this->_data->assets.GetTexture("Empty Disc").getSize();
//	for (int x = 0; x < _height; x++)
//	{
//		for (int y = 0; y < _width; y++)
//		{
//			_boardPieces[x][y].setTexture(this->_data->assets.GetTexture("Empty Disc"));
//			_boardPieces[x][y].setPosition(tempDiscSize.y * y, tempDiscSize.x * x);
//		}
//	}
//}
//
//void GameState_4x4::CheckAndPlacePiece()
//{
//	sf::Vector2i mousePoint = this->_data->input.GetMousePosition(this->_data->window);
//	int column = 0;
//	int tempWidth = this->_data->assets.GetTexture("Empty Disc").getSize().x;
//	for (int colNum = 0; colNum < _width; colNum++)
//	{
//		if ((mousePoint.x >= colNum * tempWidth) && (mousePoint.x < (colNum + 1) * (tempWidth))) {
//			column = colNum;
//		}
//	}
//
//	if (_board._grid[0][column] != EMPTY_DISC)
//	{
//		std::cout << "Column " << column + 1<< " is Full" << std::endl;
//	}
//	else if (0 <= column && column <= _width)
//	{
//		for (int row = _height - 1; row >= 0; row--)
//		{
//			if (_board._grid[row][column] == EMPTY_DISC)
//			{
//				_board._grid[row][column] = _turn;
//
//				if (_turn == PLAYER_ONE_DISC)
//				{
//					_boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player One Disc"));
//					_turn = PLAYER_TWO_DISC;
//				}
//				else if (_turn == PLAYER_TWO_DISC)
//				{
//					_boardPieces[row][column].setTexture(this->_data->assets.GetTexture("Player Two Disc"));
//					_turn = PLAYER_ONE_DISC;
//				}
//				else
//				{
//					std::cout << "Invalid Disc" << std::endl;
//				}
//				break;
//			}
//		}
//	}
//	else
//	{
//		std::cout << "Column (" << column + 1 << ") Invalid" << std::endl;
//	}
//}
//
//std::string GameState_4x4::Colour(int colour = 7, std::string message = " ")
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
//	return message;
//}
//
//void GameState_4x4::printBoard()
//{
//	for (int i = 1; i <= _width; i++)
//	{
//		std::cout << Colour(20, std::to_string(i + 1)) << " ";
//	}
//	Colour(7, " ");
//	std::cout << std::endl;
//	for (int x = 0; x < _height; x++)
//	{
//
//		for (int y = 0; y < _width; y++)
//		{
//			if (_board._grid[x][y] == PLAYER_ONE_DISC)
//			{
//				std::cout << Colour(12, "O") << " ";
//			}
//			else if (_board._grid[x][y] == PLAYER_TWO_DISC)
//			{
//				std::cout << Colour(11, "O") << " ";
//			}
//			else
//			{
//				Colour(7, " ");
//				std::cout << "O" << " ";
//			}
//		}
//		Colour(7, " ");
//		std::cout << std::endl;
//	}
//	Colour(7, " ");
//	std::cout << std::endl;
//}
//
//
//int GameState_4x4::gameEvaluation()
//{
//	return 0;
//
//}
//
//void GameState_4x4::HandleInput()
//{
//	sf::Event event;
//	sf::Vector2i pos;
//
//	while (this->_data->window.pollEvent(event))
//	{
//		if (sf::Event::Closed == event.type)
//		{
//			this->_data->window.close();
//		}
//
//		if (sf::Event::MouseButtonPressed == event.type)
//		{
//			this->CheckAndPlacePiece();
//			this->printBoard();
//		}
//	}
//}
//
//void GameState_4x4::Update(float dt)
//{
//	if (gameState == GAME_OVER)
//	{
//		if (this->_clock.getElapsedTime().asSeconds() > TRANSITION_TIME)
//		{
//			this->_data->machine.AddState(StateRef(new GameMenuState(_data)), true);
//		}
//	}
//}
//
//void GameState_4x4::Draw(float dt)
//{
//	this->_data->window.clear(sf::Color::White);
//	//this->_data->window.draw(this->_background);
//
//	for (int x = 0; x < _height; x++)
//	{
//		for (int y = 0; y < _width; y++)
//		{
//			this->_data->window.draw(this->_boardPieces[x][y]);
//		}
//	}
//	this->_data->window.display();
//}