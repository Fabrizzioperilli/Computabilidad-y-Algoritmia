// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Symbol.h
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once

#include <string.h>
#include <vector>

class Symbol {
private:
  std::vector<std::string> symbol_;

 public:
  Symbol();
  Symbol(std::vector<std::string>);
  ~Symbol();

  inline std::vector<std::string> GetSymbol();
  
  void Add(std::string);
  bool Empty();
  int SymbolSize();
  bool FindSymbol(std::string);
  void Write();
};

Symbol::Symbol() {}


Symbol::Symbol(std::vector<std::string> str) { 
    symbol_ = str; 
}


Symbol::~Symbol() {}


std::vector<std::string> Symbol::GetSymbol() { 
    return symbol_; 
}


void Symbol::Add(std::string str) { 
    symbol_.push_back(str); 
}


bool Symbol::Empty() { 
    return symbol_.empty(); 
}


int Symbol::SymbolSize() { 
    return symbol_.size(); 
}


bool Symbol::FindSymbol(std::string str) {
  for (size_t i = 0; i < symbol_.size(); i++)
    if (symbol_[i] == str) 
    return true;
}


void Symbol::Write() {
  for (size_t i = 0; i < symbol_.size(); i++) 
    std::cout << symbol_[i] << " ";
}



