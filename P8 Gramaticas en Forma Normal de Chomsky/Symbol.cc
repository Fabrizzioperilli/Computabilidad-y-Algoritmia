/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Symbol.h  implementacion de clase Symbol
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Symbol.h"

/// @brief Constructor por defecto
Symbol::Symbol() {}


/// @brief Constructor de la clase Symbol
/// @param str 
Symbol::Symbol(std::string str) { 
  symbol_ = str; 
}


/// @brief Destructor de la clase Symbol
Symbol::~Symbol() {}


/// @brief Getter de la clase Symbol
/// @return std::string
std::string Symbol::GetSymbol() { 
  return symbol_; 
}


/// @brief Setter de la clase Symbol
void Symbol::SetSymbol(std::string str) { 
  symbol_ = str; 
}


/// @brief Tamano del símbolo
/// @return int
int Symbol::SymbolSize() { 
  return symbol_.size(); 
}


/// @brief Imprime el símbolo
/// @param os 
/// @return std::ostream
std::ostream &Symbol::Write(std::ostream &os) {
  os << symbol_;
  return os;
}


/// @brief Sobrecarga del operador <
/// @param symbol
/// @return bool
bool Symbol::operator<(const Symbol &s) const { 
  return symbol_ < s.symbol_; 
}


/// @brief Sobrecarga del operador <<
/// @param os 
/// @param s 
/// @return std::ostream
std::ostream &operator<<(std::ostream &os, Symbol &s) { 
  return s.Write(os); 
}


/// @brief Sobrecarga del operador ==
/// @param s
/// @return bool
bool Symbol::operator==(const Symbol &s) const { 
  return symbol_ == s.symbol_; 
}


/// @brief Sobrecarga del operador !=
/// @param s
/// @return bool
bool Symbol::operator!=(const Symbol &s) const { 
  return symbol_ != s.symbol_; 
}


/// @brief Sobrecarga del operador >>
/// @param is 
/// @param s 
/// @return std::istream
std::istream &operator>>(std::istream &is, Symbol &s) {
  is >> s.symbol_;
  return is;
}