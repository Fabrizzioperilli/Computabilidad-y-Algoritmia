// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de automatas finitos
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 08/11/2022
// Archivo:  Transition.h Defincion de la clase Transition
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 02/11/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Symbol.h"
#include "State.h"
#pragma once

class State;
class Transition {
 //automata finito no determinista
  private:
    Symbol symbol_;
    int next_state_;
  public:
    Transition();
    Transition(Symbol&, int);
    ~Transition();
    Symbol GetSymbol() const;
    void SetSymbol(Symbol&);
    int GetNextState() const;
    void SetNextState(int);
    void write(void);

    bool operator<(const Transition&) const;
};

Transition::Transition() {}

Transition::~Transition() {}

Transition::Transition(Symbol& symbol, int next_state) {
  symbol_ = symbol;
  next_state_ = next_state;
}

bool Transition::operator<(const Transition& transition) const {
  return symbol_ < transition.symbol_;
}

Symbol Transition::GetSymbol() const {
  return symbol_;
}

void Transition::SetSymbol(Symbol& symbol) {
  symbol_ = symbol;
}

int Transition::GetNextState() const {
  return next_state_;
}

void Transition::SetNextState(int next_state) {
  next_state_ = next_state;
}

