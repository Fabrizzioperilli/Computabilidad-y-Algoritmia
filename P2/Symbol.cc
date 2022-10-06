// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Symbol.cc   La clase simbolo almacena un string
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Symbol.h"

Symbol::Symbol() {}


Symbol::Symbol(std::string str) { 
    symbol_ = str; 
}


Symbol::~Symbol() {}


std::string Symbol::GetSymbol() { 
    return symbol_; 
}


void Symbol::SetSymbol(std::string str) { 
    symbol_ = str; 
}


int Symbol::SymbolSize() { 
    return symbol_.size(); 
}


std::ostream& Symbol::Write(std::ostream &os) {
    os << symbol_;
    return os;
}

bool Symbol::operator<(const Symbol &s) const {
    return symbol_ < s.symbol_;
}

std::ostream& operator<<(std::ostream &os, Symbol &s) {
    return s.Write(os);
}

bool Symbol::operator==(const Symbol &s) const {
    return symbol_ == s.symbol_;
}