// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Language.cc    La clase alfabeto almacena un vector de Simbolos
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "Word.h"
#include <set>

class Language {
  private: 
  std::set<Word> language_;
  Alphabet alphabet_;
  
  public:
  Language();
  Language(Word&, Alphabet&);
  ~Language();

  std::set<Word> getLanguage();
  Alphabet getAlphabet();
  void AddWord(Word&);
  void SetAlphabet(Alphabet&);
  std::ostream& Write(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, Language&);
  
  Language Concatenate(Language&);
  Language Union(Language&);
  Language Intersection(Language&);
  Language Difference(Language&);
  Language Inverse();
  Language Power(int);

};


Language::Language() {}


Language::Language(Word& word, Alphabet& alphabet) {
  language_.insert(word);
  alphabet_ = alphabet;
}
  
Alphabet Language::getAlphabet() {
  return alphabet_;
}

void Language::SetAlphabet(Alphabet& alphabet) {
  alphabet_ = alphabet;
}


Language::~Language() {}

void Language::AddWord(Word& word) {
  language_.insert(word);
}

std::ostream& Language::Write(std::ostream& os) {
  for (auto i : language_)
    os << i << " ";
  return os;
}

std::ostream& operator<<(std::ostream& os, Language& language) {
  return language.Write(os);
}

Language Language::Concatenate(Language& language) {  
  Language result;
  
  Alphabet alpha = alphabet_.Union(language.getAlphabet());
  result.SetAlphabet(alpha);

  for (auto i : language_) 
    for (auto j : language.getLanguage()) {
      Word word;
      word = i + j;
      result.AddWord(word);
    }
  return result;
}

Language Language::Union(Language& language) {
  Language result;
  for (auto i : language_) 
    result.AddWord(i);
  for (auto i : language.getLanguage()) 
    result.AddWord(i);
  return result;
}

std::set<Word> Language::getLanguage() {
  return language_;
}

Language Language::Intersection(Language& language) {
  Language result;
  for (auto i : language_) 
    for (auto j : language.getLanguage()) {
      if (i == j)
        result.AddWord(i);
    }
  return result;
}

Language Language::Difference(Language& language) {
  Language result;
  for (auto i : language_) 
    for (auto j : language.getLanguage()) {
      if (i != j)
        result.AddWord(i);
    }
  return result;
}

Language Language::Inverse() {
  Language result;
  for (auto i : language_) {
    Word word = i.WordInverse();
    result.AddWord(word);
  }
  return result;
}



Language Language::Power(int n = 1) {
  Language result;
  for (auto i : language_) {
    Word word = i;
    for (int j = 1; j < n; j++) {
      word = word + i;
    }
    result.AddWord(word);
  }
  return result;
}
