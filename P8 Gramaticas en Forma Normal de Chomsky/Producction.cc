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


Production::Production() {}

Production::Production(Symbol symbol_left, Word &production) {
  symbol_left_ = symbol_left;
  production_ = production;
}

std::ostream &Production::WriteProduction(std::ostream &os) {
  os << symbol_left_ << " -> " << production_;
  return os;
}

bool Production::operator<(const Production &production) const {
  if (symbol_left_ < production.symbol_left_) {
    return true;
  } else if (symbol_left_ == production.symbol_left_) {
    if (production_ < production.production_) {
      return true;
    }
  }
  return false;
}

std::ostream &operator<<(std::ostream &os, Production &production) {
  production.WriteProduction(os);
  return os;
}

std::istream &operator>>(std::istream &is, Production &production) {
  is >> production.symbol_left_;
  is.ignore(3);
  is >> production.production_;
  return is;
}

Word Production::GetProduction() { 
  return production_; 
}
