// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo: Symbol.h  Cabecera de la clase simbolo
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#pragma once

#include <iostream>
#include <string.h>
#include <vector>

const std::string STR_EMPTY = "&";

class Symbol {
private:
  std::string symbol_;

 public:
  Symbol();
  Symbol(std::string);
  ~Symbol();

  std::string GetSymbol();
  void SetSymbol(std::string);
  
 
  int SymbolSize();

  std::ostream& Write(std::ostream &os);
  bool operator<(const Symbol&) const;
  friend std::ostream& operator<<(std::ostream&, Symbol&);
  bool operator==(const Symbol&) const;
  bool operator!=(const Symbol&) const;
};