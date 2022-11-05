// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de automatas finitos
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 08/11/2022
// Archivo:  State.h Defincion de la clase State
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 02/11/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once 
#include <set>
#include <vector>
class Transition;
class State {
  private:
    int id_;
    std::vector<Transition> transitions_;  
  
  public:
    State();
    ~State();
  
  
    int GetId() const;
    void SetId(int);
    std::vector<Transition> GetTransitions() const;
    void SetTransitions(std::vector<Transition>);
    void AddTransition(Transition&);
    void write(void);

    bool operator<(const State&) const;
};

State::State() {}
State::~State() {}


int State::GetId() const {
  return id_;
}


void State::SetId(int id) {
  id_ = id;
}

std::vector<Transition> State::GetTransitions() const {
  return transitions_;
}


void State::SetTransitions(std::vector<Transition> transitions) {
  transitions_ = transitions;
}

bool State::operator<(const State& state) const {
  return id_ < state.id_;
}

void State::AddTransition(Transition& transition) {
  transitions_.push_back(transition);
}

void State::write(void) {
  std::cout << "State: " << id_ << std::endl;
}

