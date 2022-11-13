#include "Player.hpp"

//std::string Player::getSummary()
//{
//	return std::to_string(getAverageRowWeight2EvalDiff());
//}

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

long long Player::getAverageTime()
{
	return 1.0 * std::accumulate(timeVector.begin(), timeVector.end(), 0LL) / timeVector.size();
}

double Player::getAverageRowEval()
{
	return 1.0 * std::accumulate(rowEvalVector.begin(), rowEvalVector.end(), 0LL) / rowEvalVector.size();
}

double Player::getAverageWeight1Eval()
{
	return 1.0 * std::accumulate(weight1EvalVector.begin(), weight1EvalVector.end(), 0LL) / weight1EvalVector.size();
}

double Player::getAverageWeight2Eval()
{
	return 1.0 * std::accumulate(weight2EvalVector.begin(), weight2EvalVector.end(), 0LL) / weight2EvalVector.size();
}

double Player::getAverageWeight3Eval()
{
	return 1.0 * std::accumulate(weight3EvalVector.begin(), weight3EvalVector.end(), 0LL) / weight3EvalVector.size();
}

double Player::getAverageRowWeight1Eval()
{
	return 1.0 * std::accumulate(rowWeight1EvalVector.begin(), rowWeight1EvalVector.end(), 0LL) / rowWeight1EvalVector.size();
}

double Player::getAverageRowWeight2Eval()
{
	return 1.0 * std::accumulate(rowWeight2EvalVector.begin(), rowWeight2EvalVector.end(), 0LL) / rowWeight2EvalVector.size();
}

double Player::getAverageRowWeight3Eval()
{
	return 1.0 * std::accumulate(rowWeight3EvalVector.begin(), rowWeight3EvalVector.end(), 0LL) / rowWeight3EvalVector.size();
}


long long Player::getMaxTime()
{
	return *std::max_element(timeVector.begin(), timeVector.end());
}

int Player::getMaxRowEval()
{
	return *std::max_element(rowEvalVector.begin(), rowEvalVector.end());
}

int Player::getMaxWeight1Eval()
{
	return *std::max_element(weight1EvalVector.begin(), weight1EvalVector.end());
}

int Player::getMaxWeight2Eval()
{
	return *std::max_element(weight2EvalVector.begin(), weight2EvalVector.end());
}

int Player::getMaxWeight3Eval()
{
	return *std::max_element(weight3EvalVector.begin(), weight3EvalVector.end());
}

int Player::getMaxRowWeight1Eval()
{
	return *std::max_element(rowWeight1EvalVector.begin(), rowWeight1EvalVector.end());
}

int Player::getMaxRowWeight2Eval()
{
	return *std::max_element(rowWeight2EvalVector.begin(), rowWeight2EvalVector.end());
}

int Player::getMaxRowWeight3Eval()
{
	return *std::max_element(rowWeight3EvalVector.begin(), rowWeight3EvalVector.end());
}

long long Player::getMinTime()
{
	return *std::min_element(timeVector.begin(), timeVector.end());
}

int Player::getMinRowEval()
{
	return *std::min_element(rowEvalVector.begin(), rowEvalVector.end());
}

int Player::getMinWeight1Eval()
{
	return *std::min_element(weight1EvalVector.begin(), weight1EvalVector.end());
}

int Player::getMinWeight2Eval()
{
	return *std::min_element(weight2EvalVector.begin(), weight2EvalVector.end());
}

int Player::getMinWeight3Eval()
{
	return *std::min_element(weight3EvalVector.begin(), weight3EvalVector.end());
}

int Player::getMinRowWeight1Eval()
{
	return *std::min_element(rowWeight1EvalVector.begin(), rowWeight1EvalVector.end());
}

int Player::getMinRowWeight2Eval()
{
	return *std::min_element(rowWeight2EvalVector.begin(), rowWeight2EvalVector.end());
}

int Player::getMinRowWeight3Eval()
{
	return *std::min_element(rowWeight3EvalVector.begin(), rowWeight3EvalVector.end());
}

double Player::getAverageRowEvalDiff()
{
	return 1.0 * std::accumulate(rowEvalDiff.begin(), rowEvalDiff.end(), 0LL) / timeVector.size();
}

double Player::getAverageWeight1EvalDiff()
{
	return 1.0 * std::accumulate(weight1EvalDiff.begin(), weight1EvalDiff.end(), 0LL) / weight1EvalDiff.size();
}

double Player::getAverageWeight2EvalDiff()
{
	return 1.0 * std::accumulate(weight2EvalDiff.begin(), weight2EvalDiff.end(), 0LL) / weight2EvalDiff.size();
}

double Player::getAverageWeight3EvalDiff()
{
	return 1.0 * std::accumulate(weight3EvalDiff.begin(), weight3EvalDiff.end(), 0LL) / weight3EvalDiff.size();
}

double Player::getAverageRowWeight1EvalDiff()
{
	return 1.0 * std::accumulate(rowWeight1EvalDiff.begin(), rowWeight1EvalDiff.end(), 0LL) / rowWeight1EvalDiff.size();
}

double Player::getAverageRowWeight2EvalDiff()
{
	return 1.0 * std::accumulate(rowWeight2EvalDiff.begin(), rowWeight2EvalDiff.end(), 0LL) / rowWeight2EvalDiff.size();
}

double Player::getAverageRowWeight3EvalDiff()
{
	return 1.0 * std::accumulate(rowWeight3EvalDiff.begin(), rowWeight3EvalDiff.end(), 0LL) / rowWeight3EvalDiff.size();
}


double Player::getMaxRowEvalDiff() 
{
	return *std::max_element(rowEvalDiff.begin(), rowEvalDiff.end());
}

double Player::getMaxWeight1EvalDiff()
{
	return *std::max_element(weight1EvalDiff.begin(), weight1EvalDiff.end());
}

double Player::getMaxWeight2EvalDiff()
{
	return *std::max_element(weight2EvalDiff.begin(), weight2EvalDiff.end());
}

double Player::getMaxWeight3EvalDiff()
{
	return *std::max_element(weight3EvalDiff.begin(), weight3EvalDiff.end());
}

double Player::getMaxRowWeight1EvalDiff()
{
	return *std::max_element(rowWeight1EvalDiff.begin(), rowWeight1EvalDiff.end());
}

double Player::getMaxRowWeight2EvalDiff()
{
	return *std::max_element(rowWeight2EvalDiff.begin(), rowWeight2EvalDiff.end());
}

double Player::getMaxRowWeight3EvalDiff()
{
	return *std::max_element(rowWeight3EvalDiff.begin(), rowWeight3EvalDiff.end());
}



double Player::getMinRowEvalDiff()
{
	return *std::min_element(rowEvalDiff.begin(), rowEvalDiff.end());
}

double Player::getMinWeight1EvalDiff()
{
	return *std::min_element(weight1EvalDiff.begin(), weight1EvalDiff.end());
}

double Player::getMinWeight2EvalDiff()
{
	return *std::min_element(weight2EvalDiff.begin(), weight2EvalDiff.end());
}

double Player::getMinWeight3EvalDiff()
{
	return *std::min_element(weight3EvalDiff.begin(), weight3EvalDiff.end());
}

double Player::getMinRowWeight1EvalDiff()
{
	return *std::min_element(rowWeight1EvalDiff.begin(), rowWeight1EvalDiff.end());
}

double Player::getMinRowWeight2EvalDiff()
{
	return *std::min_element(rowWeight2EvalDiff.begin(), rowWeight2EvalDiff.end());
}

double Player::getMinRowWeight3EvalDiff()
{
	return *std::min_element(rowWeight3EvalDiff.begin(), rowWeight3EvalDiff.end());
}

void Player::displayResult()
{
	std::cout << "Time taken: " << timeVector.back() << std::endl;
	std::cout << "The rowEval: " << rowEval << std::endl;
	std::cout << "The weight1Eval: " << weight1Eval << std::endl;
	std::cout << "The weight2Eval: " << weight2Eval << std::endl;
	std::cout << "The weight3Eval: " << weight3Eval << std::endl;
	std::cout << "The rowWeight1Eval: " << rowWeight1Eval << std::endl;
	std::cout << "The rowWeight2Eval: " << rowWeight2Eval << std::endl;
	std::cout << "The rowWeight3Eval: " << rowWeight3Eval << std::endl;
}