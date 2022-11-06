// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 6: Simulacion de automatas finitos
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 08/11/2022
// Archivo:  Automata.h Defincion de la clase Automaton
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 02/11/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <set>
#include <fstream>
#include <iostream>
#include <vector>

#include "Symbol.h"
#include "Alphabet.h"
#include "Word.h"
#include "State.h"
#include "Transition.h"

#pragma once
std::vector<std::string> Split(std::string, char);

class Automata
{
private:
  std::set<State> states_;
  Alphabet alphabet_;
  std::set<Transition> transitions_;
  State initial_state_;
  std::set<State> acceptance_states_;

public:
  Automata();
  Automata(std::string);
  ~Automata();

  bool ReadWord(Word &);
  std::set<State> GesStates() const;
  Alphabet GetAlphabet() const;
  std::set<Transition> GetTransitions() const;
  State GetInitialState() const;
  std::set<State> GetAcceptanceState() const;
};

Automata::Automata() {}
Automata::~Automata() {}

Automata::Automata(std::string file_fa)
{
  std::ifstream name_file_fa(file_fa);
  std::string line;

  if (name_file_fa.is_open())
  {
    getline(name_file_fa, line);
    std::vector<std::string> symbols = Split(line, ' ');
    Symbol symbol;

    for (size_t i = 0; i < symbols.size(); i++)
    {
      symbol.SetSymbol(symbols[i]);
      alphabet_.AddSymbol(symbol);
    }

    name_file_fa >> line;
    int n_states = stoi(line);

    if (n_states == 0)
    {
      std::cout << "Error: El numero de estados del automata no puede ser 0" << std::endl;
      exit(1);
    }

    name_file_fa >> line;
    initial_state_.SetId(stoi(line));

    int i = 0;
    while (i < n_states)
    {
      int id;
      int acceptance;
      int n_transitions;

      State state;
      name_file_fa >> id;
      state.SetId(id);

      name_file_fa >> acceptance;
      name_file_fa >> n_transitions;

      for (int j = 0; j < n_transitions; j++)
      {
        std::string aux_symbol;
        int next_state;
        name_file_fa >> aux_symbol;

        Symbol symbol(aux_symbol);

        if (!alphabet_.CheckSymbol(symbol))
        {
          std::cout << "Error: El simbolo " << aux_symbol << " no pertenece al alfabeto del automata" << std::endl;
          exit(1);
        }

        name_file_fa >> next_state;
        Transition transition(symbol, next_state);
        state.AddTransition(transition);
      }

      if (acceptance == 1)
        acceptance_states_.insert(state);

      if (state.GetId() == initial_state_.GetId())
        initial_state_ = state;

      states_.insert(state);

      i++;
    }

    std::cout << "Alfabeto: " << alphabet_ << std::endl;
    std::cout << "n_states: " << n_states << std::endl;
    std::cout << "initial_state: " << initial_state_.GetId() << std::endl;
    // muestra las transiciones del estado inicial
    std::cout << "Transiciones del estado inicial: " << std::endl;
    std::set<Transition> transitions = initial_state_.GetTransitions();
    for (auto it = transitions.begin(); it != transitions.end(); it++)
    {
      std::cout << "Simbolo: " << it->GetSymbol().GetSymbol() << " Estado: " << it->GetNextState() << std::endl;
    }

    std::cout << "acceptance_states: " << std::endl;
    for (auto &&i : acceptance_states_)
      std::cout << i.GetId() << std::endl;
    std::cout << "----" << std::endl;

    for (auto &&i : acceptance_states_)
    {
      std::cout << "Transiciones del estado de aceptacion: " << i.GetId() << std::endl;
      for (auto &&i : i.GetTransitions())

        std::cout << "Simbolo: " << i.GetSymbol().GetSymbol() << " Estado: " << i.GetNextState() << std::endl;
    }

    for (auto &&i : states_)
    {
      std::cout << "state: " << i.GetId() << std::endl;
      std::cout << "num_transitions: " << i.GetTransitions().size() << std::endl;
      for (auto &&j : i.GetTransitions())
      {
        std::cout << "transition: " << j.GetSymbol().GetSymbol() << " " << j.GetNextState() << std::endl;
      }
      std::cout << "----" << std::endl;
    }

    name_file_fa.close();
  }
  else
  {
    std::cout << "No se puede abrir o no existe el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
}

Alphabet Automata::GetAlphabet() const
{
  return alphabet_;
}

bool Automata::ReadWord(Word &word)
{
  State current_state = initial_state_;
  std::set<Transition> transitions = current_state.GetTransitions();
  std::vector<Symbol> symbols = word.GetWord();

 for (auto &&i : symbols)
  {
    for (auto &&j : transitions)
    {
      if (i == j.GetSymbol())
      {
        current_state.SetId(j.GetNextState());
        current_state.SetTransitions(states_.find(current_state)->GetTransitions());
        transitions = current_state.GetTransitions();

      
        break;
      }
    }
  }

  for (auto &&i : acceptance_states_)
    if (current_state.GetId() == i.GetId())
      return true;
  

  return false;
}



std::vector<std::string> Split(std::string str, char pattern)
{
  int pos_init = 0;
  int pos_found = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (pos_found >= 0)
  {
    pos_found = str.find(pattern, pos_init);
    splitted = str.substr(pos_init, pos_found - pos_init);
    pos_init = pos_found + 1;
    results.push_back(splitted);
  }
  return results;
}