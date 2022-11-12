/**
* @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
* @details Grado en Ingenierıa Informatica
* @details Asignatura: Computabilidad y Algoritmia
* @details Curso: 2º
*          Practica 7: Gramtica regular a partir de DFA
* @author Fabrizzio Daniell Perilli Martin
*   Correo: alu0101138589@ull.edu.es
* @date Fecha: 15/11/2022
* @file Archivo: Alphabet.cc  Implementacion de clase Alphabet
* Referencias:
* @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción: Creación del código.
*/

#include "Alphabet.h"


/// @brief Constructor por defecto
Alphabet::Alphabet() {}


/// @brief Constructor de la clase Alphabet
/// @param symbol
Alphabet::Alphabet(std::set<Symbol> symbol) { 
    alphabet_ = symbol; 
}


/// @brief Destructor de la clase Alphabet
Alphabet::~Alphabet() {}


/// @brief Getter de la clase Alphabet
/// @return
std::set<Symbol> Alphabet::GetAlphabet() const { 
    return alphabet_; 
}


/// @brief Setter de la clase Alphabet
/// @param symbol
void Alphabet::AddSymbol(Symbol &symbol) { 
    alphabet_.insert(symbol); 
}


/// @brief Método que añade un símbolo al alfabeto
/// @param str
void Alphabet::AddSymbol(std::string str) {
  Symbol symbol(str);
  alphabet_.insert(symbol);
}


/// @brief Método que compruba si el alfabeto está vacío
/// @return Retorna true si el alfabeto está vacío, false en caso contrario
bool Alphabet::Empty() { 
    return alphabet_.empty(); 
}


/// @brief Retorna el tamaño del alfabeto
/// @return int
int Alphabet::Size() { 
    return alphabet_.size(); 
}


/// @brief Busca un string en el alfabeto
/// @param str
/// @return bool
bool Alphabet::Search(std::string str) {
  for (auto i : alphabet_)
    if (i.GetSymbol() == str || str == STR_EMPTY)
      return true;
  return false;
}


/// @brief Escribir el alfabeto
/// @param os
/// @return std::ostream&
std::ostream &Alphabet::Write(std::ostream &os) {
  for (auto i : alphabet_)
    os << i << " ";
  return os;
}


/// @brief Realiza la unión de dos alfabetos
/// @param alphabet
/// @return Alphabet
Alphabet Alphabet::Union(const Alphabet &alphabet) {
  Alphabet new_alphabet;
  for (auto i : alphabet_)
    new_alphabet.AddSymbol(i);
  for (auto i : alphabet.GetAlphabet())
    new_alphabet.AddSymbol(i);
  return new_alphabet;
}


/// @brief Busca un símbolo en el alfabeto
/// @param symbol
/// @return
bool Alphabet::CheckSymbol(Symbol &symbol) {
  for (auto i : alphabet_)
    if (i == symbol || symbol.GetSymbol() == STR_EMPTY)
      return true;
  return false;
}


/// @brief Sobrecarga del operador <<
/// @param os
/// @param alphabet
/// @return std::ostream&
std::ostream &operator<<(std::ostream &os, Alphabet &alphabet) {
  return alphabet.Write(os);
}