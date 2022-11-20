/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Grammar.h  Clase Grammar
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include <set>

#include "Alphabet.h"
#include "Production.h"
#include "Symbol.h"

class Grammar {
 private:
  Alphabet alphabet_;
  std::set<Symbol> non_terminal_symbols_;
  Symbol start_symbol_;
  std::set<Production> productions_;
  void CheckFormatFile(std::ifstream &);

 public:
  Grammar();
  Grammar(std::string);
  Grammar(Alphabet &, std::set<Symbol> &, Symbol &, std::set<Production> &);
  ~Grammar();

  Alphabet GetAlphabet() const;
  std::set<Symbol> GetNonTerminalSymbols() const;
  Symbol GetStartSymbol() const;
  std::set<Production> GetProductions() const;

  bool CheckCleanGrammar(Production &);
  void AddProduction(Production &);
  Grammar Convert2CNF();

  std::ostream &WriteGrammar(std::ostream &);
  friend std::ostream &operator<<(std::ostream &, Grammar &);
};