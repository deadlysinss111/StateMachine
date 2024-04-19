#pragma once
class StateMachine
{
private:
	std::vector<State*> _states;
	State* _currentState;

public:
	std::vector<State*> GetStates() { return _states; };
	State* GetCurrentState() { return _currentState; };
	void SetCurrentState(State* state) { _currentState = state; };

public:
	void AddState(State*);
	void RemoveState(State*);
	int CheckPresence(State*);

	void swapTo(char* name);
};


// States are meant to be overrided and the child will contain all contextual specificities of the wished state.
class State 
{
protected:
	State() {};
	~State() {};

public:
	char* _name;
	//void* _trigger;

protected:
	void (*_release)();
	std::vector<State*> _links;

public:
	static State* CreatState();
	void DestroyState();

public:
	void SetLinks(std::vector<State*> links) { _links = links; };
	std::vector<State*> GetLinks() { return _links; };
	void AddLink(State* link) { _links.push_back(link) ; };
	void SetRelease(void(func)()) { _release = func; }
	//void SetRelease(void* func) { _release = (void(*)())func; }
};