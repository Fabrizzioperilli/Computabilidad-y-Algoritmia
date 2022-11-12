/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 7: Gramtica regular a partir de DFA
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 15/11/2022
* @file Archivo: Transition.h
*        Clase Transition
* Referencias:
* @version Historial de revisiones:11/1/2022 - Versión: 1.0 - Descripción: Creación del código.
*/
#pragma once

#include "Symbol.h"
#include "State.h"
#include <iostream>

class Transition
{
private:
  Symbol symbol_;
  int next_state_;
  int current_state_;

public:
  Transition();
  Transition(int, Symbol &, int);
  ~Transition();

  Symbol GetSymbol() const;
  int GetNextState() const;
  int GetCurrentState() const;
  void SetSymbol(Symbol &);
  void SetNextState(int);

  bool operator<(const Transition &) const;
  friend std::ostream &operator<<(std::ostream &, Transition &);

  void Write();
};