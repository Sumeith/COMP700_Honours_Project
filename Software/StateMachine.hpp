#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;

class StateMachine
{
public:
	StateMachine() {}
	~StateMachine() {}
	void AddState(StateRef newState, bool isReplacing = true);
	void RemoveState();

	void StateTransition();

	StateRef& GetActiveState();
private:
	std::stack<StateRef> _gameStatesStack;
	StateRef _newState;
	bool _isAdding, _isReplacing;
	bool _isRemoving;
};