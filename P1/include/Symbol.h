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

#include <vector>
#include <string.h>

class Symbol
{
private:
    std::vector<std::string> symbol_;

public:
    Symbol();
    Symbol(std::vector<std::string>);
    ~Symbol();
    void write();

    void uniqueSymbol(char);
    void add(std::string);
    inline std::string getSymbol();
    
};

Symbol::Symbol(std::vector<std::string> str)
{
    symbol_ = str;
}

Symbol::Symbol() {}

Symbol::~Symbol() {}

void Symbol::add(std::string str)
{
    symbol_.push_back(str);
}

void Symbol::write(){

    for (size_t i = 0; i < symbol_.size(); i++)
        std::cout << symbol_[i] << " ";
}

void Symbol::uniqueSymbol(char c){
  
    for (size_t i = 0; i < symbol_.size(); i++)
    {
        symbol_[i].append(1, c);
        std::cout << symbol_[i] << " ";
    }
    
}

std::string Symbol::getSymbol(){
    std::string str;
    for (size_t i = 0; i < symbol_.size(); i++)
        str = symbol_[i];
    return str;
}