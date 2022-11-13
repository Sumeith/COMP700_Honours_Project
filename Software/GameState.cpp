#include "GameState.hpp"

std::string GameState::Colour(int colour = 7, std::string message = " ")
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	return message;
}

void GameState::printBoard(Board_4x4* board)
{
	int width = WIDTH_4x4;
	int height = HEIGHT_4x4;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_7x4* board)
{
	int width = WIDTH_7x4;
	int height = HEIGHT_7x4;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_4x7* board)
{
	int width = WIDTH_4x7;
	int height = HEIGHT_4x7;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_7x6* board)
{
	int width = WIDTH_7x6;
	int height = HEIGHT_7x6;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_6x7* board)
{
	int width = WIDTH_6x7;
	int height = HEIGHT_6x7;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_8x8* board)
{
	int width = WIDTH_8x8;
	int height = HEIGHT_8x8;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_14x12* board)
{
	int width = WIDTH_14x12;
	int height = HEIGHT_14x12;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}

void GameState::printBoard(Board_12x14* board)
{
	int width = WIDTH_12x14;
	int height = HEIGHT_12x14;
	for (int i = 1; i <= width; i++)
	{
		std::cout << Colour(20, std::to_string(i)) << " ";
	}
	Colour(7, " ");
	std::cout << std::endl;
	for (int x = 0; x < height; x++)
	{

		for (int y = 0; y < width; y++)
		{
			if (board->_grid[x][y] == PLAYER_ONE_DISC)
			{
				std::cout << Colour(12, "O") << " ";
			}
			else if (board->_grid[x][y] == PLAYER_TWO_DISC)
			{
				std::cout << Colour(11, "O") << " ";
			}
			else
			{
				Colour(7, " ");
				std::cout << "O" << " ";
			}
		}
		Colour(7, " ");
		std::cout << std::endl;
	}
	Colour(7, " ");
	std::cout << std::endl;
	
}