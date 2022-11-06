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

class Transition
{
private:
  Symbol symbol_;
  int next_state_;

public:
  Transition();
  Transition(Symbol &, int);
  ~Transition();

  Symbol GetSymbol() const;
  int GetNextState() const;
  void SetSymbol(Symbol &);
  void SetNextState(int);

  void write(void);
  void NextTransition(Transition &);
  bool operator<(const Transition &) const;
};

Transition::Transition() {}

Transition::~Transition() {}

Transition::Transition(Symbol &symbol, int next_state)
{
  symbol_ = symbol;
  next_state_ = next_state;
}

bool Transition::operator<(const Transition &transition) const
{
  if ((this->GetSymbol() == transition.GetSymbol()) && (this->GetNextState() < transition.GetNextState()))
    return true;
  else if (this->GetSymbol() < transition.GetSymbol())
    return true;
  else
    return false;
}

Symbol Transition::GetSymbol() const
{
  return symbol_;
}


void Transition::SetSymbol(Symbol &symbol)
{
  symbol_ = symbol;
}

int Transition::GetNextState() const
{
  return next_state_;
}


void Transition::SetNextState(int next_state)
{
  next_state_ = next_state;
}

void Transition::NextTransition(Transition &transition)
{
  this->symbol_ = transition.GetSymbol();
  this->next_state_ = transition.GetNextState();
}