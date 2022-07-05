#include "StateMachine.hpp"

void StateMachine::AddState(StateRef newState, bool isReplacing)
{
	this -> _isReplacing = isReplacing;
	this-> _isAdding = true;
	this->_newState = std::move(newState);
}

void StateMachine::RemoveState()
{
	this->_isRemoving = true;
}
void StateMachine::StateTransition()
{
	if (this->_isRemoving && !this->_gameStatesStack.empty())
	{
		this->_gameStatesStack.pop();
		if (!this->_gameStatesStack.empty())
		{
			this->_gameStatesStack.top()->Resume();
		}
		this->_isRemoving = false;
	}

	if (this->_isAdding)
	{
		if (!this->_gameStatesStack.empty())
		{
			if (this->_isReplacing)
			{
				this->_gameStatesStack.pop();
			}
			else
			{
				this->_gameStatesStack.top()->Pause();
			}
		}
		this->_gameStatesStack.push(std::move(this->_newState));
		this->_gameStatesStack.top()->Init();
		this->_isAdding = false;
	}
}

StateRef& StateMachine::GetActiveState()
{
	return this->_gameStatesStack.top();
}