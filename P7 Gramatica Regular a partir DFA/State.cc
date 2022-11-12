/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 7: Gramtica regular a partir de DFA
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 15/11/2022
* @file Archivo: State.cc
*        Implementacion de clase State
* Referencias:
* @version Historial de revisiones:11/1/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#include "Transition.h"
#include "State.h"


/// @brief Constructor por defecto
State::State() {}


/// @brief Constructor de la clase State
/// @param id 
State::State(int id) {
  id_ = id;
}

/// @brief Destructor de la clase State
State::~State() {}


/// @brief Retorna el id del estado
/// @return int
int State::GetId() const {
  return id_;
}


/// @brief Modifica el id del estado
/// @param id 
void State::SetId(int id) {
  id_ = id;
}


/// @brief Retorna las transiciones del estado
/// @return std::set<Transition>
std::set<Transition> State::GetTransitions() const {
  return transitions_;
}


/// @brief Modifica las transiciones del estado
/// @param transitions 
void State::SetTransitions(std::set<Transition> transitions) {
  transitions_ = transitions;
}


/// @brief Añade una transición al estado
/// @param transition 
void State::AddTransition(Transition& transition) {
  transitions_.insert(transition);
}


/// @brief Sobrecarga del operador <
/// @param state 
/// @return bool
bool State::operator<(const State& state) const {
  return id_ < state.id_;
}


/// @brief Sobre carga del operador =
/// @param s 
/// @return State&
State& State::operator=(const State &s) {
  id_ = s.id_;
  transitions_ = s.transitions_;
  return *this;
}


/// @brief Compara si dos estados son iguales
/// @param s 
/// @return 
bool State::operator==(const State &s) const {
  return id_ == s.id_;
}








