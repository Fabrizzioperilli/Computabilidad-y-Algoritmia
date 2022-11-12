/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 7: Gramtica regular a partir de DFA
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 15/11/2022
* @file Archivo: NonTerminalSymbol.cc  Implementacion clase NonTerminalSymbol
* Referencias:
* @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#include "NonTerminalSymbol.h"


NonTerminalSymbol::NonTerminalSymbol() {}

NonTerminalSymbol::NonTerminalSymbol(char name) {
  name_ = name;
}

NonTerminalSymbol::~NonTerminalSymbol() {}

char NonTerminalSymbol::GetName() const {
  return name_;
}

void NonTerminalSymbol::SetName(char name) {
  name_ = name;
}

// std::set<Production> NonTerminalSymbol::GetProductions() const {
//   return productions_;
// }


// void NonTerminalSymbol::SetProductions(std::set<Production> productions) {
//   productions_ = productions;
// }

// void NonTerminalSymbol::AddProduction(Production& production) {
//   productions_.insert(production);
// }

bool NonTerminalSymbol::operator<(const NonTerminalSymbol& non_terminal_symbol) const {
  return name_ < non_terminal_symbol.name_;
}


std::ostream& NonTerminalSymbol::WriteNonTerminalSymbol(std::ostream& os) {
  os << name_;
  return os;
}


std::ostream &operator<<(std::ostream &os, NonTerminalSymbol &non_terminal_symbol) {
  return non_terminal_symbol.WriteNonTerminalSymbol(os);
}

bool NonTerminalSymbol::operator==(const NonTerminalSymbol& non_terminal_symbol) const {
  return name_ == non_terminal_symbol.name_;
}