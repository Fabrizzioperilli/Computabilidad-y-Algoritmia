// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Word.cc  La clase cadena contine un vector de simbolos
//                    y tiene asociado un alfabeto
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Word.h"

Word::Word() {}

Word::Word(std::string str, Alphabet &alph) {
  alphabet_ = alph;
  std::string symbol;
  std::string sub_string;

  //Previamente se comprueba si el alfabeto asociado a la cadena está vacio
  if (!alph.Empty()) {
    for (auto i : alphabet_.getAlphabet()) {
      symbol = i.GetSymbol();
    
      for (size_t j = 0; j < str.length(); j++) {
        sub_string = str.substr(j, symbol.length());
        if (alphabet_.Search(sub_string)) {
          Symbol symbol(sub_string);
          word_.push_back(symbol);
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


Word::~Word() {}

int Word::WordLength() { 
    return word_.size(); 
}


void Word::WordInverse(std::ostream &os) {
  for (int i = word_.size() - 1; i >= 0; i--) {
    os << word_[i].GetSymbol();
  }
  os << std::endl;
}


void Word::WordPrefixes(std::ostream &os) {
  os << STR_EMPTY << " ";
  for (size_t i = 0; i < word_.size(); i++) {
    for (size_t j = 0; j <= i; j++) {
      os << word_[j].GetSymbol();
    }
    os << " ";
  }
  os << std::endl;
}


void Word::WordSuffixes(std::ostream &os) {
  os << STR_EMPTY << " ";
  for (int i = word_.size() - 1; i >= 0; i--) {
    for (size_t j = i; j < word_.size(); j++) {
      os << word_[j].GetSymbol();
    }
    os << " ";
  }
  os << std::endl;
}


void Word::WordSubstrings(std::ostream &os) {
  os << STR_EMPTY << " ";
  for (size_t i = 0; i < word_.size(); i++)
    for (size_t j = i; j < word_.size(); j++) {
      for (size_t k = i; k <= j; k++) os << word_[k].GetSymbol();
      os << " ";
    }
  os << std::endl;
}


void Word::Write() {
  for (size_t i = 0; i < word_.size(); i++) 
      word_[i].Write();
}