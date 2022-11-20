/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 8: Graticas en Forma Normal de Chomsky
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 22/11/2022
 * @file Archivo: Word.h  Implementacion de clase Word
 * Referencias:
 * @version Historial de revisiones:23/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include "Word.h"

/// @brief Constructor por defecto
Word::Word() {}


/// @brief Constructor de la clase Word 
/// @param str 
/// @param alph 
Word::Word(std::string str, Alphabet &alph) {
  alphabet_ = alph;
  std::string symbol;
  std::string sub_string;

  // Previamente se comprueba si el alfabeto asociado a la cadena está vacio
  if (!alph.Empty()) {
    for (auto i : alphabet_.GetAlphabet()) {
      symbol = i.GetSymbol();

      for (size_t j = 0; j < str.length(); j++) {
        sub_string = str.substr(j, symbol.length());
        if (alphabet_.Search(sub_string)) {
          Symbol symbol(sub_string);
          word_.push_back(symbol);
        }
        else {
          std::cout << "Error: El símbolo " << sub_string << " no pertenece al alfabeto" << std::endl;
          exit(EXIT_FAILURE);
        }
      }
      break;
    }
  } else {
    for (size_t i = 0; i < str.length(); i++) {
      std::string str_aux;
      Symbol symbol(str_aux.append(1, str[i]));
      alphabet_.AddSymbol(symbol);
      word_.push_back(symbol);
    }
  }
}


/// @brief Destructor de la clase Word
Word::~Word() {}


/// @brief Getter de la clase Word
/// @return std::vector<Symbol>
std::vector<Symbol> Word::GetWord() { 
  return word_; 
}


/// @brief Setter de la clase Word
/// @param word 
void Word::SetWord(std::vector<Symbol> word) { 
  word_ = word; 
}


/// @brief Retorna el alphabeto de la cadena
/// @return Alphabet
Alphabet Word::GetAlphabet() { 
  return alphabet_; 
}


/// @brief Modifica el alfabeto de la cadena
/// @param alph 
void Word::SetAlphabet(Alphabet &alph) { 
  alphabet_ = alph; 
}


/// @brief Agraga un símbolo a la cadena
/// @param symbol 
void Word::AddSymbol(Symbol &symbol) { 
  word_.push_back(symbol); 
}


/// @brief Rwetorna el tamaño de la cadena-
/// @return int
int Word::WordLength() { 
  return word_.size(); 
}


/// @brief Calcula la inversa de la cadena
/// @return Word
Word Word::WordInverse() {
  Word word;
  for (int i = word_.size() - 1; i >= 0; i--)
    word.word_.push_back(word_[i]);
  return word;
}


/// @brief Concatena dos cadenas
/// @param w 
/// @return Word 
Word Word::WordConcatenate(Word &w) {
  Word word;
  word.word_ = word_;
  for (size_t i = 0; i < w.word_.size(); i++)
    word.word_.push_back(w.word_[i]);
  return word;
}


/// @brief Imprime la cadena
/// @param os 
/// @return std::ostream
std::ostream &Word::Write(std::ostream &os) {
  for (size_t i = 0; i < word_.size(); i++)
    os << word_[i].GetSymbol();
  return os;
}


/// @brief Sobrecarga del operador + para concatenar dos cadenas
/// @param word 
/// @return Word
Word Word::operator+(Word &word) { 
  return WordConcatenate(word); 
}


/// @brief Sobrecarga del operador < para comparar dos cadenas
/// @param w 
/// @return bool
bool Word::operator<(const Word &w) const { 
  return word_ < w.word_; 
}


/// @brief Sobre carga del operador == para comparar dos cadenas
/// @param w 
/// @return bool
bool Word::operator==(const Word &w) const { 
  return word_ == w.word_; 
}


/// @brief Sobre carga del operador != para comparar dos cadenas
/// @param w 
/// @return bool
bool Word::operator!=(const Word &w) const { 
  return word_ != w.word_; 
}


/// @brief Sobrecarga del operador << para imprimir una cadena
/// @param os 
/// @param w 
/// @return std::ostream
std::ostream &operator<<(std::ostream &os, Word &w) { 
  return w.Write(os); 
}


/// @brief Sobrecarga del operador >> para leer una cadena
/// @param is 
/// @param w 
/// @return 
std::istream &operator>>(std::istream &is, Word &w) {
  std::string str;
  is >> str;
  w = Word(str, w.alphabet_);
  return is;
}
