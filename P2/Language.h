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
  // Alphabet alphabet_;
  
  public:
  Language();
  // Language(Word&, Alphabet&);
  Language(Word&);
  ~Language();

  std::set<Word> getLanguage();
  void AddWord(Word&);
  std::ostream& Write(std::ostream&);
  friend std::ostream& operator<<(std::ostream&, Language&);
  //Funcion que concatene dos lenguajes y devuelva el resultado
  Language Concatenate(Language&);
};


Language::Language() {}


Language::Language(Word& word) {
  language_.insert(word);
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
  for (auto i : language_) 
    for (auto j : language.getLanguage()) {
      Word word;
      word = i + j;
      result.AddWord(word);
    }
  return result;
}

std::set<Word> Language::getLanguage() {
  return language_;
}