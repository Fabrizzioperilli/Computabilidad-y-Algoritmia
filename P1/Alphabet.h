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

class Alphabet
{
private:
    std::vector<Symbol> alphabet_;

public:
    Alphabet() {}
    Alphabet(std::vector<Symbol>);
    ~Alphabet() {}
    void write();
    void add(Symbol&);
    bool empty();
    std::vector<Symbol> getAlphabet(){
        return alphabet_;
    }

    void setAlphabet(std::vector<Symbol> sym){
        alphabet_ = sym;
    }
    int nSymbol(){
        return alphabet_[0].nSymbol();
    }

    bool inAlphabet(std::string str){
        return alphabet_[0].findSymbol(str);
    }
};

Alphabet::Alphabet(std::vector<Symbol> symbol)
{
    alphabet_ = symbol;
}

void Alphabet::add(Symbol &symbol)
{
    alphabet_.push_back(symbol);
}

void Alphabet::write()
{
    for (size_t i = 0; i < alphabet_.size(); i++)
        alphabet_[i].write();
}

bool Alphabet::empty()
{
    return alphabet_.empty();
}