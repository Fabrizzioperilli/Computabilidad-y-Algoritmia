/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 7: Gramtica regular a partir de DFA
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 15/11/2022
* @file Archivo: Automata.h  Clase Automata
* Referencias:
* @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#pragma once

#include <set>
#include <fstream>
#include <iostream>
#include <vector>

#include "Symbol.h"
#include "Alphabet.h"
#include "Word.h"
#include "State.h"
#include "Transition.h"
#include "Grammar.h"
#include "NonTerminalSymbol.h"
#include "Production.h"


std::vector<std::string> Split(std::string, char);

class Automata {
private:
  std::set<State> states_;
  Alphabet alphabet_;
  std::set<Transition> transitions_;
  State initial_state_;
  std::set<State> acceptance_states_;
  
  State GetState(int);
  bool IsAcceptanceState(std::set<State>);

public:
  Automata();
  Automata(std::string);
  ~Automata();

  Alphabet GetAlphabet() const;
  bool CheckWord(Word &);
  std::ostream& WriteAutomata(std::ostream&);
  Grammar ConvertToGrammar();

  friend std::ostream &operator<<(std::ostream &, Automata &);
};