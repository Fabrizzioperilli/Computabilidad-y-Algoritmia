/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: Production.h  Clase Production
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#pragma once
#include <utility>

#include "Alphabet.h"
#include "NonTerminalSymbol.h"
#include "Symbol.h"

class Production {
 private:
  NonTerminalSymbol left_;
  std::pair<Symbol, NonTerminalSymbol> production_;

 public:
  Production();
  Production(NonTerminalSymbol, std::pair<Symbol, NonTerminalSymbol>);
  ~Production();
  std::ostream &WriteProduction(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, Production &);
  bool operator<(const Production &) const;
};