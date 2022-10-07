// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Alphabet.cc    La clase alfabeto almacena un vector de Simbolos
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Alphabet.h"

Alphabet::Alphabet() {}


Alphabet::Alphabet(std::set<Symbol> symbol) { 
    alphabet_ = symbol; 
}


Alphabet::~Alphabet() {}


void Alphabet::AddSymbol(Symbol &symbol) { 
    alphabet_.insert(symbol); 
}

void Alphabet::AddSymbol(std::string str) {
    Symbol symbol(str);
    alphabet_.insert(symbol);
}

bool Alphabet::Empty() { 
    return alphabet_.empty(); 
}


std::set<Symbol> Alphabet::getAlphabet() const{ 
    return alphabet_; 
}


int Alphabet::Size() { 
    return alphabet_.size(); 
}


bool Alphabet::Search(std::string str) {
    for (auto i : alphabet_)
        if (i.GetSymbol() == str || str == STR_EMPTY)
            return true;
    return false;
}


std::ostream& Alphabet::Write(std::ostream& os) {
    for (auto i : alphabet_)
        os << i << " ";
    return os;
}

std::ostream& operator<<(std::ostream& os, Alphabet& alphabet) {
    return alphabet.Write(os);
}

Alphabet Alphabet::Union(const Alphabet& alphabet){
    Alphabet new_alphabet;
    for (auto i : alphabet_)
        new_alphabet.AddSymbol(i);
    for (auto i : alphabet.getAlphabet())
        new_alphabet.AddSymbol(i);
    return new_alphabet;
}

