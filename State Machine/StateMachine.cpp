#include "pch.h"


// STATE MACHINE


void StateMachine::AddState(State* state) { 
	state->SetRelease((void(*)())(&std::bind(RemoveState, state)));
	_states.push_back(state);
}

void StateMachine::RemoveState(State* state) {
	int index = CheckPresence(state);
	if (index != -1) {
		_states.erase(_states.begin() + index);
	}
}

int StateMachine::CheckPresence(State* state) {
	for (int i = 0; i < _states.size(); i++) {
		if (_states.at(i) == state) {
			return i;
		}
	}
	return -1;
}

void StateMachine::swapTo(char* name) {
	for (State* state : _currentState->GetLinks()) {
		if (name == state->_name) {
			SetCurrentState(state);
			return;
		}
	}
	throw(std::invalid_argument("Specified state linked to current state."));
}





// STATE


State* State::CreatState() {
	State* state = new State;
	return state;
}

void State::DestroyState() {
	_release();
	delete this;
}
