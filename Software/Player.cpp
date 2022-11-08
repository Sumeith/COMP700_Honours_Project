#include "Player.hpp"

void Player::calcEvaluation_4x4(Board_4x4* board)
{
	this->rowEval = rowEval_4x4(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_4x4(board);
	this->weight2Eval = weight2Eval_4x4(board);
	this->weight3Eval = weight3Eval_4x4(board);
	this->rowWeight1Eval = rowWeight1_4x4(board);
	this->rowWeight2Eval = rowWeight2_4x4(board);
	this->rowWeight3Eval = rowWeight3_4x4(board);
}

void Player::calcEvaluation_7x4(Board_7x4* board) 
{
	this->rowEval = rowEval_7x4(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_7x4(board);
	this->weight2Eval = weight2Eval_7x4(board);
	this->weight3Eval = weight3Eval_7x4(board);
	this->rowWeight1Eval = rowWeight1_7x4(board);
	this->rowWeight2Eval = rowWeight2_7x4(board);
	this->rowWeight3Eval = rowWeight3_7x4(board);
}

void Player::calcEvaluation_4x7(Board_4x7* board) 
{
	this->rowEval = rowEval_4x7(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_4x7(board);
	this->weight2Eval = weight2Eval_4x7(board);
	this->weight3Eval = weight3Eval_4x7(board);
	this->rowWeight1Eval = rowWeight1_4x7(board);
	this->rowWeight2Eval = rowWeight2_4x7(board);
	this->rowWeight3Eval = rowWeight3_4x7(board);
}

void Player::calcEvaluation_7x6(Board_7x6* board) 
{
	this->rowEval = rowEval_7x6(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_7x6(board);
	this->weight2Eval = weight2Eval_7x6(board);
	this->weight3Eval = weight3Eval_7x6(board);
	this->rowWeight1Eval = rowWeight1_7x6(board);
	this->rowWeight2Eval = rowWeight2_7x6(board);
	this->rowWeight3Eval = rowWeight3_7x6(board);
}

void Player::calcEvaluation_6x7(Board_6x7* board) 
{
	this->rowEval = rowEval_6x7(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_6x7(board);
	this->weight2Eval = weight2Eval_6x7(board);
	this->weight3Eval = weight3Eval_6x7(board);
	this->rowWeight1Eval = rowWeight1_6x7(board);
	this->rowWeight2Eval = rowWeight2_6x7(board);
	this->rowWeight3Eval = rowWeight3_6x7(board);
}

void Player::calcEvaluation_8x8(Board_8x8* board) 
{
	this->rowEval = rowEval_8x8(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_8x8(board);
	this->weight2Eval = weight2Eval_8x8(board);
	this->weight3Eval = weight3Eval_8x8(board);
	this->rowWeight1Eval = rowWeight1_8x8(board);
	this->rowWeight2Eval = rowWeight2_8x8(board);
	this->rowWeight3Eval = rowWeight3_8x8(board);
}

void Player::calcEvaluation_14x12(Board_14x12* board) 
{
	this->rowEval = rowEval_14x12(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_14x12(board);
	this->weight2Eval = weight2Eval_14x12(board);
	this->weight3Eval = weight3Eval_14x12(board);
	this->rowWeight1Eval = rowWeight1_14x12(board);
	this->rowWeight2Eval = rowWeight2_14x12(board);
	this->rowWeight3Eval = rowWeight3_14x12(board);
}

void Player::calcEvaluation_12x14(Board_12x14* board) 
{
	this->rowEval = rowEval_12x14(board); this->eval = rowEval;
	this->weight1Eval = weight1Eval_12x14(board);
	this->weight2Eval = weight2Eval_12x14(board);
	this->weight3Eval = weight3Eval_12x14(board);
	this->rowWeight1Eval = rowWeight1_12x14(board);
	this->rowWeight2Eval = rowWeight2_12x14(board);
	this->rowWeight3Eval = rowWeight3_12x14(board);
}

int Player::getEvaluation()
{
	return eval;
}

int Player::getRowEvaluation()
{
	return rowEval;
}

int Player::getWeight1Evaluation()
{
	return weight1Eval;
}

int Player::getWeight2Evaluation()
{
	return weight2Eval;
}

int Player::getWeight3Evaluation()
{
	return weight3Eval;
}

int Player::getRowWeight1Eval()
{
	return rowWeight1Eval;
}

int Player::getRowWeight2Eval()
{
	return rowWeight2Eval;
}

int Player::getRowWeight3Eval()
{
	return rowWeight3Eval;
}