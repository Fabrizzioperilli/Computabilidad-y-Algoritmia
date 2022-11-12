/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: Production.cc  Implementacion de clase Production
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Production.h"

/// @brief Constructor por defecto
Production::Production() {}


/// @brief Constructor con parametros
/// @param left
/// @param production
Production::Production(NonTerminalSymbol left, std::pair<Symbol, NonTerminalSymbol> production) {
  left_ = left;
  production_ = production;
}


/// @brief Destructor
Production::~Production() {}


/// @brief Escribe la produccion de la gramatica
/// @param os 
/// @return std::ostream
std::ostream& Production::WriteProduction(std::ostream& os) {
  os << left_ << " -> " << production_.first << production_.second;
  return os;
}


/// @brief Sobrecarga del operador << 
/// @param os 
/// @param production 
/// @return std::ostream&
std::ostream& operator<<(std::ostream& os, Production& production) {
  production.WriteProduction(os);
  return os;
}


/// @brief Sobrecarga del operador <
/// @param production 
/// @return bool
bool Production::operator<(const Production& production) const {
  if (left_ < production.left_)
    return true;
  else if (left_ == production.left_) {
    if (production_.first < production.production_.first) 
      return true;
    else if (production_.first == production.production_.first)
      if (production_.second < production.production_.second)
        return true;      
    }
  return false;
  }

