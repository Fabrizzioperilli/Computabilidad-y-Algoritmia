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

  std::set<State> get_states() const;
  Alphabet get_alphabet() const;
  std::set<Transition> get_transitions() const;
  State get_initial_state() const;
  std::set<State> get_acceptance_states() const;
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
      bool acceptance;
      int n_transitions;

      State state;
      name_file_fa >> id;
      state.SetId(id);

      name_file_fa >> acceptance;

      if (acceptance == 1)
        acceptance_states_.insert(state);

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
      states_.insert(state);
      i++;
    }

    std::cout << "Alfabeto: " << alphabet_ << std::endl;
    std::cout << "n_states: " << n_states << std::endl;
    std::cout << "initial_state: " << initial_state_.GetId() << std::endl;

    for (auto &&i : states_)
      std::cout << "state: " << i.GetId() << std::endl;

    name_file_fa.close();
  }
  else
  {
    std::cout << "No se puede abrir o no existe el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
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