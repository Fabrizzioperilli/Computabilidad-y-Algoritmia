/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: Grammar.h  Clase Grammar
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#pragma once

#include "Symbol.h"
#include "Alphabet.h"
#include <set>

class Grammar {
private:
  Alphabet alphabet_;
  std::set<Symbol> non_terminal_symbols_;
  Symbol initial_symbol_;
  std::set<Symbol> productions_;
public:
  Grammar();
  Grammar(Alphabet, std::set<Symbol>, Symbol);
  ~Grammar();

  std::ostream& WriteGrammar(std::ostream&);
  friend std::ostream &operator<<(std::ostream &, Grammar &);
};