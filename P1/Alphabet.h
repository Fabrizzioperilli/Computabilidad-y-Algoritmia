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
#include "Symbol.h"

class Alphabet {
 private:
  std::vector<Symbol> alphabet_;

 public:
  Alphabet();
  Alphabet(std::vector<Symbol>);
  ~Alphabet();

  void Add(Symbol &);
  bool Empty();
  inline std::vector<Symbol> getAlphabet();
  int Size();
  bool Search(std::string);
  void Write();
};

Alphabet::Alphabet(){}


Alphabet::Alphabet(std::vector<Symbol> symbol) { 
    alphabet_ = symbol; 
}


Alphabet::~Alphabet(){}


void Alphabet::Add(Symbol &symbol) { 
    alphabet_.push_back(symbol); 
}


bool Alphabet::Empty() { 
    return alphabet_.empty(); 
}


std::vector<Symbol> Alphabet::getAlphabet() { 
    return alphabet_; 
}


int Alphabet::Size() { 
    return alphabet_.size(); 
}


bool Alphabet::Search(std::string str) { 
    for (size_t i = 0; i < alphabet_.size(); i++)
        if (alphabet_[i].GetSymbol() == str)
            return true;  

    return false; 
}

  
void Alphabet::Write() {
  for (size_t i = 0; i < alphabet_.size(); i++) 
      std::cout << alphabet_[i].GetSymbol() << " ";
}