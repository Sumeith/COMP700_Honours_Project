#include "Player.hpp"


std::string Player::Colour(int colour = 7, std::string message = " ")
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colour);
	return message;
}

void Player::printBoard(Board_4x4* board)
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
	std::cout << "The evaluation is : " << eval << std::endl;
}

void Player::printBoard(Board_7x6* board)
{

}

void Player::printBoard(Board_14x12* board)
{

}

bool Player::checkConditionHorizontal(int col , int width)
{
	return col < (width - 3);
}

bool Player::checkConditionVertical(int row, int height)
{
	return row < (height - 3);
}

bool Player::checkConditionPosDiag(int row, int col, int width)
{
	return row >= 3 && col < (width - 3);
}

bool Player::checkConditionNegDiag(int row, int col, int width, int height)
{
	return col < (width - 3) && row < (height - 3);
}

void Player::checkThreeInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc Disc Disc _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[0]++;
	}
	//Disc Disc Disc _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[5]++;
	}

	//Disc Disc _ Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//Disc Disc _ Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}

	//Disc _ Disc Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//Disc _ Disc Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}

	//_ Disc Disc Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[0]++;
	}
	//_ Disc Disc Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[5]++;
	}
}

void Player::checkTwoInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc Disc _ _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//Disc Disc _ _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//Disc _ Disc _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//Disc _ Disc _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//Disc _ _ Disc
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//Disc _ _ Disc
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}

	//_ Disc Disc _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[1]++;
	}

	//_ Disc Disc _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[4]++;
	}

	//_ Disc _ Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//_ Disc _ Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}

	//_ _ Disc Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[1]++;
	}

	//_ _ Disc Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[4]++;
	}
}

void Player::checkOneInARow(Discs boardDisc1, Discs boardDisc2, Discs boardDisc3, Discs boardDisc4, int evalArr[])
{
	//Disc _ _ _
	if (boardDisc1 == PLAYER_ONE_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//Disc _ _ _
	else if (boardDisc1 == PLAYER_TWO_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ Disc _ _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_ONE_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//_ Disc _ _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == PLAYER_TWO_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ _ Disc _
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_ONE_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[2]++;
	}
	//_ _ Disc _
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == PLAYER_TWO_DISC &&
		boardDisc4 == EMPTY_DISC)
	{
		evalArr[3]++;
	}

	//_ _ _ Disc
	if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_ONE_DISC)
	{
		evalArr[2]++;
	}
	//_ _ _ Disc
	else if (boardDisc1 == EMPTY_DISC &&
		boardDisc2 == EMPTY_DISC &&
		boardDisc3 == EMPTY_DISC &&
		boardDisc4 == PLAYER_TWO_DISC)
	{
		evalArr[3]++;
	}

}