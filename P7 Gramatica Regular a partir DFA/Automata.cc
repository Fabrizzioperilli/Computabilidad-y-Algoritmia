/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: Automata.cc  Implementacion de la clase Automata
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
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
      std::cout << "Error: El numero de estados del automata no puede ser 0" << std::endl;
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
          std::cout << "Error: El simbolo " << aux_symbol << " no pertenece al alfabeto del automata" << std::endl;
          exit(1);
        }

        name_file_fa >> next_state;
        Transition transition(state.GetId(), symbol, next_state);
        transitions_.insert(transition);
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
/// @return Alphabet
Alphabet Automata::GetAlphabet() const { return alphabet_; }


/// @brief Compruba si la cadena es aceptada o rechaza por el automata
/// @param word
/// @return bool
bool Automata::CheckWord(Word &word) {
  std::set<State> current_state;
  current_state.insert(initial_state_);

  std::vector<Symbol> symbols = word.GetWord();

  for (auto &&iter_symbol : symbols) {
    std::set<State> next_state;
    for (auto &&iter_state : current_state)
      for (auto &&iter_transition : transitions_)
        if ((iter_symbol == iter_transition.GetSymbol()) &&
            (iter_state == iter_transition.GetCurrentState()))
          next_state.insert(GetState(iter_transition.GetNextState()));

    current_state = next_state;
  }
  return IsAcceptanceState(current_state);
}


/// @brief Imprime los elementos del automata
/// @param os
/// @return std::ostream&
std::ostream &Automata::WriteAutomata(std::ostream &os) {
  std::cout << "Alfabeto: " << alphabet_ << std::endl;
  std::cout << "Estados: ";
  for (auto &&i : states_) std::cout << i.GetId() << " ";
  std::cout << std::endl;

  std::cout << "Estado inicial: " << initial_state_.GetId() << std::endl;
  std::cout << "Estados de aceptacion: ";
  for (auto &&i : acceptance_states_) std::cout << i.GetId() << " ";
  std::cout << std::endl;

  std::cout << "Transiciones: " << std::endl;
  for (auto i : transitions_) std::cout << i << std::endl;
  return os;
}


/// @brief Convierte un automata a una gramatica regular
Grammar Automata::ConvertToGrammar() {
  std::set<Production> set_productions;
  NonTerminalSymbol initial_non_terminal_symbol;
  std::set<NonTerminalSymbol> set_non_terminal_symbols;

  for (auto i : transitions_) {
    std::pair<Symbol, NonTerminalSymbol> production_aux;
    if (i.GetCurrentState() == initial_state_.GetId()) {
      initial_non_terminal_symbol.SetName('S');
      set_non_terminal_symbols.insert(initial_non_terminal_symbol);
      production_aux.first = i.GetSymbol();
      if (i.GetCurrentState() != i.GetNextState()) {
        production_aux.second = NonTerminalSymbol(char(i.GetNextState() + 64));
        set_productions.insert(Production(NonTerminalSymbol('S'), production_aux));
      } else {
        production_aux.second = NonTerminalSymbol('S');
        set_productions.insert(Production(NonTerminalSymbol('S'), production_aux));
      }
    } else {
      production_aux.first = i.GetSymbol();
      production_aux.second = NonTerminalSymbol(char(i.GetNextState() + 64));
      set_non_terminal_symbols.insert(NonTerminalSymbol(char(i.GetNextState() + 64)));
      set_productions.insert(Production(NonTerminalSymbol(char(i.GetCurrentState() + 64)), production_aux));
    }
  }

  for (auto i : acceptance_states_) {
    std::pair<Symbol, NonTerminalSymbol> production_aux;
    production_aux.first = Symbol(STR_EMPTY);
    production_aux.second = NonTerminalSymbol(' ');
    set_productions.insert(Production(NonTerminalSymbol(char(i.GetId() + 64)), production_aux));
  }

  return Grammar(alphabet_, set_non_terminal_symbols, initial_non_terminal_symbol, set_productions);
}


/// @brief Sobrecarga del operador <<
/// @param os
/// @param automata
/// @return
std::ostream &operator<<(std::ostream &os, Automata &automata) {
  return automata.WriteAutomata(os);
}


/// @brief Metodo privado que el estado con el id pasado por parametro
/// @param id
/// @return State
State Automata::GetState(int id) {
  for (auto &&i : states_)
    if (i.GetId() == id) return i;
  return -1;
}


/// @brief Compara si el estado pasado por parametro es de aceptacion
/// @param current_state
/// @return bool
bool Automata::IsAcceptanceState(std::set<State> current_state) {
  for (auto &&i : current_state)
    if (acceptance_states_.find(i) != acceptance_states_.end()) return true;
  return false;
}


/// @brief Corta una cadena en un vector de cadenas
/// @param str
/// @param pattern
/// @return std::vector<std::string>
std::vector<std::string> Split(std::string str, char pattern) {
  int pos_init = 0;
  int pos_found = 0;
  std::string splitted;
  std::vector<std::string> results;

  while (pos_found >= 0) {
    pos_found = str.find(pattern, pos_init);
    splitted = str.substr(pos_init, pos_found - pos_init);
    pos_init = pos_found + 1;
    results.push_back(splitted);
  }
  return results;
}