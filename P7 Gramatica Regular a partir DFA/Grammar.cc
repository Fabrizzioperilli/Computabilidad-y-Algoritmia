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

/// @brief Constructor por defecto de la clase Grammar.
Grammar::Grammar() {}


/// @brief Constructor de la clase Grammar.
/// @param alphabet 
/// @param non_terminal_symbols 
/// @param start_symbol 
/// @param productions 
Grammar::Grammar(Alphabet alphabet, std::set<NonTerminalSymbol> non_terminal_symbols,
                 NonTerminalSymbol start_symbol, std::set<Production> productions) {
  alphabet_ = alphabet;
  non_terminal_symbols_ = non_terminal_symbols;
  start_symbol_ = start_symbol;
  productions_ = productions;
}


/// @brief Destructor de la clase Grammar.
Grammar::~Grammar() {}


/// @brief Getter de alphabet_.
/// @return Alphabet
Alphabet Grammar::GetAlphabet() const { 
  return alphabet_; 
}


/// @brief Imprime la gramatica.
/// @param os 
/// @return std::ostream&
std::ostream& Grammar::WriteGrammar(std::ostream& os) {
  os << alphabet_.Size() << std::endl;
  for (auto symbol : alphabet_.GetAlphabet()) 
    os << symbol << std::endl;
  
  os << non_terminal_symbols_.size() << std::endl;
  for (auto non_terminal_symbol : non_terminal_symbols_)
    os << non_terminal_symbol.GetName() << std::endl;

  os << start_symbol_ << std::endl;
  os << productions_.size() << std::endl; 
 
  for (auto production : productions_) 
    os << production << std::endl;
  
  return os;
}


/// @brief Sobrecarga del operador <<.
/// @param os 
/// @param grammar 
/// @return std::ostream&
std::ostream &operator<<(std::ostream &os, Grammar &grammar) {
  return grammar.WriteGrammar(os);
}