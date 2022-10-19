// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Program.h Definicion de la clase Program.h
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <fstream>
#include <iostream>
#include <regex>
#include "Variable.h"
#pragma once

const std::regex regex_int("(\\s*(int)\\s+(\\w+)\\s*(\\=\\s*\\d+)?\\s*\\;.*)");

class Analyzer
{
private:
  int count_lines_ = 0;
  std::string namefile_input_;
  std::vector<Variable> vector_int_;

public:
  Analyzer();
  Analyzer(std::string);
  ~Analyzer();

  void SetNameFile(std::string name);
  std::string GetNameFile();
  void Check();
  std::ostream &Write(std::ostream &os);

  friend std::ostream &operator<<(std::ostream &, Analyzer &);
};

Analyzer::Analyzer() {}

Analyzer::~Analyzer() {}

Analyzer::Analyzer(std::string input)
{
  namefile_input_ = input;
}

void Analyzer::SetNameFile(std::string name)
{
  namefile_input_ = name;
}

std::string Analyzer::GetNameFile()
{
  return namefile_input_;
}

void Analyzer::Check()
{
  std::ifstream input_file(namefile_input_, std::ios::in);
  if (input_file.fail())
  {
    std::cout << "Error. El fichero de entrada no existe" << std::endl;
    exit(EXIT_FAILURE);
  }

  std::string line;
  while (!input_file.eof())
  {
    getline(input_file, line);
    count_lines_++;

    if (regex_match(line, regex_int))
    {
      Variable var_int(line, count_lines_, 1);
      vector_int_.push_back(var_int);
    }
  }
}

std::ostream &Analyzer::Write(std::ostream &os)
{
  for (size_t i = 0; i < vector_int_.size(); i++)
    os << vector_int_[i] << std::endl;

  return os;
}

std::ostream &operator<<(std::ostream &os, Analyzer &program)
{
  return program.Write(os);
}