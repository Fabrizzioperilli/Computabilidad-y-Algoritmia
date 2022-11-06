/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 6: Simulacion de Automatas Finitos
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 18/10/2022
* @file Archivo: Transition.h
*        Clase Transition
* Referencias:
* @version Historial de revisiones:12/10/2022 - Versión: 1.0 - Descripción: Creación del código.
*/
#pragma once

#include "Symbol.h"
#include "State.h"

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

  bool operator<(const Transition &) const;
};