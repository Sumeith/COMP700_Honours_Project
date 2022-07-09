#include "Player.hpp"

int Player::getEvaluation()
{
	return eval;
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

bool Player::checkConditionNegDiag(int row, int col, int height, int width)
{
	return col < (width - 3) && row < (height - 3);
}

/*
* This function checks if there are 3 Discs in a winning position for a player
* and updates the evlauation array accordingly.
* 
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position 
* 
* This function looks for the following combinations:
* Disc Disc Disc _
* Disc Disc _ Disc
* Disc _ Disc Disc
* _ Disc Disc Disc
*/
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

/*
* This function checks if there are 2 Discs in a winning position for a player
* and updates the evlauation array accordingly.
*
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position
*
* This function looks for the following combinations:
* Disc Disc _ _
* Disc _ Disc _
* Disc _ _ Disc
* _ Disc Disc _
* _ Disc _ Disc
* _ _ Disc Disc
*/
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

/*
* This function checks if there are 1 Disc in a winning position for a player
* and updates the evlauation array accordingly.
*
* Procided that:	Disc	: Represents a player disc
*					_		: Represents an empty position
*
* This function looks for the following combinations:
* Disc _ _ _
* _ Disc _ _
* _ _ Disc _
* _ _ _ Disc
*/
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