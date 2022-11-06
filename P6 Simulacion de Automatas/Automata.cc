/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 6: Simulacion de Automatas Finitos
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 18/10/2022
 * @file Archivo: Automata.h
 *        Implementación de clase Automata
 * Referencias:
 * @version Historial de revisiones:12/10/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Automata.h"

/// @brief Constructor por defecto
Automata::Automata() {}


/// @brief Constructor de la clase Automata
/// @param file_fa 
Automata::Automata(std::string file_fa) {
  std::ifstream name_file_fa(file_fa);
  std::string line;

  if (name_file_fa.is_open()) {
    getline(name_file_fa, line);
    std::vector<std::string> symbols = Split(line, ' ');
    Symbol symbol;

    for (size_t i = 0; i < symbols.size(); i++) {
      symbol.SetSymbol(symbols[i]);
      alphabet_.AddSymbol(symbol);
    }

    name_file_fa >> line;
    int n_states = stoi(line);

    if (n_states == 0) {
      std::cout << "Error: El numero de estados del automata no puede ser 0"
                << std::endl;
      exit(1);
    }

    name_file_fa >> line;
    initial_state_.SetId(stoi(line));

    int i = 0;
    while (i < n_states) {
      int id;
      int acceptance;
      int n_transitions;

      State state;
      name_file_fa >> id;
      state.SetId(id);

      name_file_fa >> acceptance;
      name_file_fa >> n_transitions;

      for (int j = 0; j < n_transitions; j++) {
        std::string aux_symbol;
        int next_state;
        name_file_fa >> aux_symbol;

        Symbol symbol(aux_symbol);

        if (!alphabet_.CheckSymbol(symbol)) {
          std::cout << "Error: El simbolo " << aux_symbol
                    << " no pertenece al alfabeto del automata" << std::endl;
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
    name_file_fa.close();
  } else {
    std::cout << "No se puede abrir o no existe el archivo" << std::endl;
    exit(EXIT_FAILURE);
  }
}


/// @brief Destructor de la clase Automata
Automata::~Automata() {}


/// @brief Retorna el alfabeto del automata
/// @return 
Alphabet Automata::GetAlphabet() const { 
  return alphabet_; 
}


/// @brief Lee las cadenas de un fichero
/// @param word 
/// @return 
bool Automata::ReadWord(Word &word) {
  State current_state = initial_state_;
  std::set<Transition> transitions = current_state.GetTransitions();
  std::vector<Symbol> symbols = word.GetWord();

  for (auto &&i : symbols) {
    for (auto &&j : transitions) {
      if (i == j.GetSymbol()) {
        current_state.SetId(j.GetNextState());
        current_state.SetTransitions(
            states_.find(current_state)->GetTransitions());
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


/// @brief Corta una cadena en un vector de cadenas
/// @param str 
/// @param pattern 
/// @return std::vector<std::string>
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