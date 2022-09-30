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

const std::string STR_EMPTY = "&";
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
    std::string wordInverse();
   
    void searchSymbol();
    void write();
};

Word::Word(std::string str, Alphabet &alph)
{

    word_ = str;
    alphabet_ = alph;
}


void Word::searchSymbol()
{
    std::vector<std::string> aux;

    for (size_t i = 0; i < word_.length(); i++)
    {
       alphabet_.getAlphabet()[0].uniqueSymbol(word_[i]);
    }
}

void Word::write()
{
    for (size_t i = 0; i < word_.size(); i++)
        std::cout << word_[i];
}

int Word::wordLength()
{
    return word_.length();
}

std::string Word::wordInverse()
{
    std::string aux;
    for (size_t i = word_.length(); i > 0; i--)
    {
        aux += word_[i - 1];
    }
    return aux;
}
