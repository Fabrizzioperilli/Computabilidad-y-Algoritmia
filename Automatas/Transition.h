
#include "Symbol.h"
#include <set>

class State;
class Transition {
private:
    Symbol symbol_;
    std::set<State> next_state_;
public:
    Transition();
    Transition(Symbol, std::set<State>);
    ~Transition();
    Symbol GetSymbol() const;
    std::set<State> GetNextState() const;
    void SetSymbol(Symbol);
    void SetNextState(std::set<State>);
    bool operator<(const Transition&) const;
    bool operator==(const Transition&) const;
    bool operator!=(const Transition&) const;
};

Transition::Transition() {}

Transition::Transition(Symbol symbol, std::set<State> next_state) {
    symbol_ = symbol;
    next_state_ = next_state;
}

Transition::~Transition() {}

Symbol Transition::GetSymbol() const {
    return symbol_;
}

std::set<State> Transition::GetNextState() const {
    return next_state_;
}


void Transition::SetSymbol(Symbol symbol) {
    symbol_ = symbol;
}


void Transition::SetNextState(std::set<State> next_state) {
    next_state_ = next_state;
}

bool Transition::operator<(const Transition& transition) const {
    if (symbol_ < transition.GetSymbol())
        return true;
    else if (symbol_ == transition.GetSymbol()) {
        if (next_state_ < transition.GetNextState())
            return true;
    }
    return false;
}

bool Transition::operator==(const Transition& transition) const {
    if (symbol_ == transition.GetSymbol() && next_state_ == transition.GetNextState())
        return true;
    return false;
}

bool Transition::operator!=(const Transition& transition) const {
    if (symbol_ != transition.GetSymbol() || next_state_ != transition.GetNextState())
        return true;
    return false;
}
