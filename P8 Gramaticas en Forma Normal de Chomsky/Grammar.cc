/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Grammar.cc  Implemenracion de clase Grammar
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Grammar.h"

/// @brief Constructor de copia 
Grammar::Grammar() {}


Grammar::Grammar(std::string input_file) {
  std::ifstream name_file(input_file);
  std::string aux_alphabet;
  int n_alphabet;
  int n_non_terminal;
  int n_productions;

  if (name_file.is_open()) {
    name_file >> n_alphabet;
    CheckFormatFile(name_file);

    if (n_alphabet < 1) {
      std::cout << "Error en fichero " << input_file << ": El alfabeto no puede estar vacio" << std::endl;
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_alphabet; i++) {
      name_file >> aux_alphabet;
      CheckFormatFile(name_file);
      alphabet_.AddSymbol(aux_alphabet);
    }

    name_file >> n_non_terminal;
    CheckFormatFile(name_file);

    if (n_non_terminal < 1) {
      std::cout << "Error en fichero " << input_file << ": El conjunto de simbolos no terminales no puede estar vacio" << std::endl;
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_non_terminal; i++)
    {
      Symbol symbol_non_terminal;
      name_file >> symbol_non_terminal;
      CheckFormatFile(name_file);
      non_terminal_symbols_.insert(symbol_non_terminal);
    }
    
    name_file >> start_symbol_;
    CheckFormatFile(name_file);

    name_file >> n_productions;
    CheckFormatFile(name_file);

    if (n_productions < 1) {
      std::cout << "Error en fichero " << input_file << ": La gramatica no puede estar vacia" << std::endl;
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_productions; i++) {
      Production production;
      // name_file >> production;
      CheckFormatFile(name_file);
      productions_.insert(production);
    }
    
  }
  else{
    std::cout << "No se puede abrir el fichero" << input_file << " o no existe" << std::endl;
    exit(EXIT_FAILURE);
  }
}


/// @brief Destructor de la clase Grammar.
Grammar::~Grammar() {}


/// @brief Getter de alphabet_.
/// @return Alphabet
Alphabet Grammar::GetAlphabet() const { 
  return alphabet_; 
}


/// @brief Getter de non_terminal_symbols_.
/// @return std::set<Symbol>
std::set<Symbol> Grammar::GetNonTerminalSymbols() const { 
  return non_terminal_symbols_; 
}


/// @brief Getter de start_symbol_.
/// @return Symbol
Symbol Grammar::GetStartSymbol() const { 
  return start_symbol_; 
}


void Grammar::CheckFormatFile(std::ifstream& name_file) {
  if (name_file.peek() == ' ') {
    std::cout << "Error en fichero de entrada. Formato incorrecto, comprueba que no existan espacios en blanco" << std::endl;
    exit(EXIT_FAILURE);
    }
}