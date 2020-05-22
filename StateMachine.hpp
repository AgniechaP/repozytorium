#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP
#include<memory>
#include<stack> //biblioteka do uzywania stosu
#include "State.hpp"

typedef std::unique_ptr<State> StateRef;
class StateMachine {
public:
    StateMachine(){}
    ~StateMachine(){}

    void AddState(StateRef newState, bool isReplacing = true); //czy zamieniamy biezacy stan
    //np klikajac play chcemy zeby obraz menu byl zamieniony
    void RemoveState();
    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving; //czy usuwamy state
    bool _isAdding; //dodajemy
    bool _isReplacing; //zamieniamy
};

#endif // STATEMACHINE_HPP
