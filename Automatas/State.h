
#include <set>
#include "Transition.h"
class Transition;
class State {
    private:
        int id_;
        std::set<Transition> transitions_;
        bool acceptance_;
    public:
        State();
        State(int);
        ~State();
        int GetId() const;
        std::set<Transition> GetTransitions() const;
        bool GetAcceptance() const;
        void SetId(int);
        void SetTransitions(std::set<Transition>);
        void SetAcceptance(bool);
        void AddTransition(Transition);
        bool operator<(const State&) const;
        bool operator==(const State&) const;
        bool operator!=(const State&) const;
};

State::State() {}

State::State(int id) {
    id_ = id;
}

State::~State() {}

int State::GetId() const {
    return id_;
}

std::set<Transition> State::GetTransitions() const {
    return transitions_;
}

bool State::GetAcceptance() const {
    return acceptance_;
}

void State::SetId(int id) {
    id_ = id;
}


void State::SetTransitions(std::set<Transition> transitions) {
    transitions_ = transitions;
}

void State::SetAcceptance(bool acceptance) {
    acceptance_ = acceptance;
}

void State::AddTransition(Transition transition) {
    transitions_.insert(transition);
}

bool State::operator<(const State& state) const {
    if (id_ < state.GetId())
        return true;
    else if (id_ == state.GetId()) {
        if (transitions_ < state.GetTransitions())
            return true;
    }
    return false;
}

bool State::operator==(const State& state) const {
    if (id_ == state.GetId() && transitions_ == state.GetTransitions())
        return true;
    return false;
}

bool State::operator!=(const State& state) const {
    if (id_ != state.GetId() || transitions_ != state.GetTransitions())
        return true;
    return false;
}

