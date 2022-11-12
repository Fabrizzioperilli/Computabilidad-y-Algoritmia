/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: Grammar.cc  Clase Grammar
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Grammar.h"

Grammar::Grammar() {}

Grammar::Grammar(Alphabet alphabet, std::set<Symbol> non_terminal_symbols,
                 Symbol initial_symbol) {
  alphabet_ = alphabet;
  non_terminal_symbols_ = non_terminal_symbols;
  initial_symbol_ = initial_symbol;
}

Grammar::~Grammar() {}


std::ostream &Grammar::WriteGrammar(std::ostream &os) {
  os << alphabet_.Size() << std::endl;
  
  for(auto symbol : alphabet_.GetAlphabet()) 
    os << symbol << std::endl;

  os << non_terminal_symbols_.size() << std::endl;
     
  for (auto symbol : non_terminal_symbols_) 
    os << symbol << std::endl;
  
  os << initial_symbol_ << std::endl;

  return os;
}


std::ostream &operator<<(std::ostream &os, Grammar &grammar) {
  return grammar.WriteGrammar(os);
}