// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Word.h
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once
#include "../include/Alphabet.h"

class Word
{
private:
    Alphabet alphabet_;
    std::string word_;

public:
    Word() {}
    Word(std::string, Alphabet &);
    ~Word() {}
    // Operaciones con las cadenas
    int wordLength();
    void searchSymbol();
    void write();
};

Word::Word(std::string str, Alphabet &alph)
{
    
    word_ = str;
    alphabet_ = alph;

    std::cout << "Alfabeto:  ";
    alphabet_.write();
    std::cout << std::endl;
    std::cout << "Cadena: " << word_ << std::endl;
}

int Word::wordLength()
{
    return word_.length();
}

void Word::searchSymbol()
{
    char c;
    for (size_t i = 0; i < word_.length(); i++)
    {
        std::cout << word_[i] << " ";
        c = word_[i];
        alphabet_.getAlphabet()[i].uniqueSymbol(c);

    }
}

void Word::write()
{
    alphabet_.write();
}