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
/// @param symbol_left
/// @param production
Production::Production(Symbol symbol_left, Word &production) {
  symbol_left_ = symbol_left;
  production_ = production;
}


/// @brief Destructor
Production::~Production() {}


/// @brief Getter de la producción
/// @return Word
Word Production::GetProduction() { 
  return production_; 
}


/// @brief Getter del símbolo izquierdo
/// @return Symbol
Symbol Production::GetSymbolLeft() { 
  return symbol_left_; 
}


/// @brief Setter de la producción
/// @param production 
void Production::SetProduction(Word &production) { 
  production_ = production; 
}


/// @brief Setter del símbolo izquierdo
void Production::SetSymbolLeft(Symbol symbol_left) { 
  symbol_left_ = symbol_left; 
}


/// @brief Método que imprime una producción
/// @param os
/// @return std::ostream&
std::ostream &Production::WriteProduction(std::ostream &os) {
  os << symbol_left_ << " -> " << production_;
  return os;
}


/// @brief Método de comparación de producciones
/// @param production
/// @return
bool Production::operator<(const Production &production) const {
  if (symbol_left_ < production.symbol_left_)
    return true;
  else if (symbol_left_ == production.symbol_left_)
    if (production_ < production.production_) return true;

  return false;
}


/// @brief Sobrecarfa del operador de salida
/// @param os
/// @param production
/// @return
std::ostream &operator<<(std::ostream &os, Production &production) {
  production.WriteProduction(os);
  return os;
}


/// @brief Sobrecarga del operador de entrada
/// @param is
/// @param production
/// @return std::istream&
std::istream &operator>>(std::istream &is, Production &production) {
  is >> production.symbol_left_;
  is.ignore(3);
  is >> production.production_;
  return is;
}