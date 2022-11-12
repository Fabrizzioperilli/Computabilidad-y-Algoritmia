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
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "NonTerminalSymbol.h"

/// @brief Constructor por defecto
NonTerminalSymbol::NonTerminalSymbol() {}


/// @brief Constructor por parametros 
/// @param name 
NonTerminalSymbol::NonTerminalSymbol(char name) { 
  name_ = name; 
}


/// @brief Desctructor de la clase
NonTerminalSymbol::~NonTerminalSymbol() {}


/// @brief Getter del atributo nombre
/// @return 
char NonTerminalSymbol::GetName() const {
   return name_; 
}


/// @brief Setter del atributo nombre
/// @param name 
void NonTerminalSymbol::SetName(char name) { 
  name_ = name; 
}


/// @brief Sobrecarga del operador <
/// @param non_terminal_symbol 
/// @return bool
bool NonTerminalSymbol::operator<(const NonTerminalSymbol& non_terminal_symbol) const {
  return name_ < non_terminal_symbol.name_;
}


/// @brief Escribe el nombre del simbolo
/// @param os 
/// @return std::ostream&
std::ostream& NonTerminalSymbol::WriteNonTerminalSymbol(std::ostream& os) {
  os << name_;
  return os;
}

/// @brief Sobrecarga del operador <<
/// @param os 
/// @param non_terminal_symbol 
/// @return std::ostream&
std::ostream& operator<<(std::ostream& os, NonTerminalSymbol& non_terminal_symbol) {
  return non_terminal_symbol.WriteNonTerminalSymbol(os);
}


/// @brief Sobrecarga del operador ==
/// @param non_terminal_symbol 
/// @return bool
bool NonTerminalSymbol::operator==(const NonTerminalSymbol& non_terminal_symbol) const {
  return name_ == non_terminal_symbol.name_;
}