// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: Analyzer.h Definicion de la clase Analyzer.h
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <fstream>
#include <iostream>
#include <regex>
#include "Variable.h"
#include "Loop.h"
#include "Comment.h"
#pragma once

const std::regex regex_int("(\\s*(const|static|unsigned)\\s+)?\\s*(int)\\s+(\\*)*(([a-zA-Z_][a-zA-Z0-9_]*))\\s*(\\=\\s*.+)?\\s*\\;");
const std::regex regex_double("(\\s*(const|static|unsigned)\\s+)?\\s*(double)\\s+(\\*)*(([a-zA-Z_][a-zA-Z0-9_]*))\\s*(\\=\\s*.+)?\\s*\\;");
const std::regex regex_for("(\\s*(for)\\s*\\(.*\\;.*\\;.*\\))\\s*(\\{)?");
const std::regex regex_while("\\s*(while)\\s*\\(.+\\)\\s*(\\{)?");
const std::regex regex_main("\\s*(void|int|double|float|char)\\s*(main)\\s*\\(.*\\)\\s*(\\{)?");
const std::regex regex_comment_inline("\\s*(//)\\s*.+");
const std::regex regex_comment_block_ini("\\s*\\/\\*\\s*.*");
const std::regex regex_comment_block_end("\\s*.*\\*\\/\\s*");

class Analyzer
{
private:
  int count_lines_ = 0;
  std::string namefile_input_;
  std::vector<Variable> vector_int_;
  std::vector<Variable> vector_double_;
  std::vector<Loop> vector_for_;
  std::vector<Loop> vector_while_;
  std::vector<Comment> vector_comment_inline_;
  std::vector<Comment> vector_comment_block_;
  bool main_ = false;
  bool description_ = false;

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