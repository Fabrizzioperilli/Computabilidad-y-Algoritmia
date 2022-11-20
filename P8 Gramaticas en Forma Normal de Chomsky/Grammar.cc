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


/// @brief Constructor con parametros
/// @param input_file
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

    for (int i = 0; i < n_non_terminal; i++) {
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
      std::cout << "Error en fichero " << input_file << ": Las producciones no pueden estar vacias" << std::endl;
      exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n_productions; i++) {
      Production production;
      name_file >> production;
      if (CheckCleanGrammar(production))
        productions_.insert(production);
      else {
        std::cout << "Error en fichero " << input_file << ": La gramatica no está simplicaficada. "
                     "Compruebe que no tenga producciones vacías o "
                     "producciones unitarias" << std::endl;
        exit(EXIT_FAILURE);
      }
    }

  } else {
    std::cout << "No se puede abrir el fichero" << input_file << " o no existe" << std::endl;
    exit(EXIT_FAILURE);
  }
}


/// @brief Constructor con la tupla de la gramatica
/// @param alphabet 
/// @param non_terminal_symbols 
/// @param start_symbol 
/// @param productions 
Grammar::Grammar(Alphabet& alphabet, std::set<Symbol>& non_terminal_symbols,
                 Symbol& start_symbol, std::set<Production>& productions) {
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


/// @brief Getter de productions_.
/// @return  std::set<Production>
std::set<Production> Grammar::GetProductions() const { 
  return productions_; 
}


/// @brief Comrpruba si la gramatica está limpia
/// @param production 
/// @return bool
bool Grammar::CheckCleanGrammar(Production& production) {
  if ((production.GetProduction().WordLength() == 1) &&
      (regex_match(production.GetProduction().GetWord()[0].GetSymbol(), regex_mayus)))
    return false;
  else if ((production.GetProduction().WordLength() == 1) && (production.GetProduction().GetWord()[0].GetSymbol() == STR_EMPTY)) {
    if (production.GetSymbolLeft().GetSymbol() == start_symbol_.GetSymbol())
      return true;
    else
      return false;
  }
  return true;
}


/// @brief Añade una produccion a la gramatica
/// @param production 
void Grammar::AddProduction(Production& production) {
  productions_.insert(production);
}


/// @brief Convertir la gramatica a forma normal de Chomsky
/// @return Grammar
Grammar Grammar::Convert2CNF() {
  std::set<Production> productions_cnf;
  std::set<Symbol> non_terminal_symbols_cnf = non_terminal_symbols_;
  Production aux_production;
  Symbol new_symbol;
  
  for (auto i : productions_) {
    if (i.GetProduction().WordLength() >= 2) {
      for (int j = 0; j < i.GetProduction().WordLength(); j++)
        if (alphabet_.Search(i.GetProduction().GetWord()[j].GetSymbol())) {
          std::string name_symbol = "Z" + i.GetProduction().GetWord()[j].GetSymbol();
          new_symbol.SetSymbol(name_symbol);
          Word new_word;
          new_word.AddSymbol(i.GetProduction().GetWord()[j]);
          Production new_production(new_symbol, new_word);
          productions_cnf.insert(new_production);
          non_terminal_symbols_cnf.insert(new_symbol);
          
          Word word_aux = i.GetProduction();
          word_aux.ModifySymbol(j, new_symbol);
          i.SetProduction(word_aux);
          aux_production = i;
        }
    productions_cnf.insert(aux_production);
    }
  }
  
  for (auto i : productions_) {
     if (i.GetProduction().WordLength() == 1)
        productions_cnf.insert(i);
      else if (i.GetProduction().WordLength() == 2) {
        if (non_terminal_symbols_.find(i.GetProduction().GetWord()[0]) != non_terminal_symbols_.end() &&
            non_terminal_symbols_.find(i.GetProduction().GetWord()[1]) != non_terminal_symbols_.end()) 
          productions_cnf.insert(i);
      }
  }

  return Grammar(alphabet_, non_terminal_symbols_cnf, start_symbol_, productions_cnf);
}


/// @brief Imprime la gramatica
/// @param os 
/// @return std::ostream&
std::ostream& Grammar::WriteGrammar(std::ostream& os) {
  os << alphabet_.GetAlphabet().size() << std::endl;

  for (auto i : alphabet_.GetAlphabet()) 
    os << i << std::endl;

  os << non_terminal_symbols_.size() << std::endl;

  for (auto i : non_terminal_symbols_) 
    os << i << std::endl;

  os << start_symbol_ << std::endl;
  os << productions_.size() << std::endl;

  for (auto i : productions_) 
    os << i << std::endl;
  
  return os;
}


/// @brief Sobrecarga del operador de salida
/// @param os 
/// @param grammar 
/// @return std::ostram&
std::ostream& operator<<(std::ostream& os, Grammar& grammar) {
  return grammar.WriteGrammar(os);
}


/// @brief Comprueba el formato del fichero.
/// @param name_file 
void Grammar::CheckFormatFile(std::ifstream& name_file) {
  if (name_file.peek() == ' ') {
    std::cout << "Error en fichero de entrada. Formato incorrecto, comprueba "
                 "que no existan espacios en blanco" << std::endl;
    exit(EXIT_FAILURE);
  }
}