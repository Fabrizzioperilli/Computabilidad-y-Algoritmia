// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Alphabet.h
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Alphabet.h"

const std::string STR_EMPTY = "&";

class Word {
 private:
  Alphabet alphabet_;
  std::vector<std::string> word_;

 public:
  Word();
  Word(std::string, Alphabet &);
  ~Word();

  int WordLength();
  std::string WordInverse();
  void WordPrefixes(std::ostream &);
  void WordSuffixes(std::ostream &);
  void WordSubstrings(std::ostream &);

  void Write();
};


Word::Word() {}


Word::Word(std::string str, Alphabet &alph) {
  alphabet_ = alph;
  std::string symbol;
  std::string sub_string;

  for (int i = 0; i < alphabet_.Size(); i++) {
    symbol = alphabet_.getAlphabet()[0].GetSymbol()[i];  
    
    for (size_t j = 0; j < str.length(); j++) {
      sub_string = str.substr(j, symbol.length());
      if (alphabet_.Search(sub_string)) 
        word_.push_back(sub_string);
    }
    break;
  }
}


Word::~Word() {}


int Word::WordLength() { 
    return word_.size(); 
}


std::string Word::WordInverse() {
  // std::string aux;
  // for (size_t i = word_.length(); i > 0; i--)
  //     aux += word_[i - 1];

  return "0";
}


void Word::WordPrefixes(std::ostream &os) {
  // os << STR_EMPTY << " ";
  // for (size_t i = 0; i < word_.length(); i++)
  // {
  //     for (size_t j = 0; j <= i; j++)
  //         os << word_[j];

  //     os << " ";
  // }
  // os << std::endl;
}


void Word::WordSuffixes(std::ostream &os) {
  // os << WTR_EMPTY << " ";

  // for (int i = word_.length(); i >= 0; i--)
  //     os << word_.substr(i) << " ";

  // os << std::endl;
}


void Word::WordSubstrings(std::ostream &os) {
  // os << STR_EMPTY << " ";

  // for (size_t i = 0; i < word_.length(); i++)
  // {
  //     for (size_t j = 0; j < word_.length() - i; j++)
  //         os << word_.substr(j, i + 1) << " ";
  // }
  // os << std::endl;
}


void Word::Write() {
  for (size_t i = 0; i < word_.size(); i++) 
    std::cout << word_[i] << " ";
}