/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 6: Simulacion de Automatas Finitos
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 18/10/2022
* @file Archivo: Transition.cc
*        Implementacion de clase Transition
* Referencias:
* @version Historial de revisiones:12/10/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#include "Transition.h"


/// @brief Constructor por defecto
Transition::Transition() {}


/// @brief Descructor de la clase Transition
Transition::~Transition() {}


/// @brief Constructor de la clase Transition
/// @param symbol 
/// @param next_state 
Transition::Transition(Symbol &symbol, int next_state)
{
  symbol_ = symbol;
  next_state_ = next_state;
}


/// @brief Retorna el símbolo
/// @return Symbol
Symbol Transition::GetSymbol() const
{
  return symbol_;
}


/// @brief Modiica el símbolo
/// @param symbol 
void Transition::SetSymbol(Symbol &symbol)
{
  symbol_ = symbol;
}


/// @brief Retorna el estado siguiente
/// @return int
int Transition::GetNextState() const
{
  return next_state_;
}


/// @brief Modifica el estado siguiente
/// @param next_state 
void Transition::SetNextState(int next_state)
{
  next_state_ = next_state;
}


/// @brief Sobreescritura del operador <
/// @param transition 
/// @return bool
bool Transition::operator<(const Transition &transition) const
{
  if ((this->GetSymbol() == transition.GetSymbol()) && (this->GetNextState() < transition.GetNextState()))
    return true;
  else if (this->GetSymbol() < transition.GetSymbol())
    return true;
  else
    return false;
}