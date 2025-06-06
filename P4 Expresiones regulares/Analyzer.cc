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

#include "Analyzer.h"


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

    if (regex_match(line, regex_double))
    {
      Variable var_double(line, count_lines_, 2);
      vector_double_.push_back(var_double);
    }

    if (regex_match(line, regex_for))
    {
      Loop loop_for(line, count_lines_, 1);
      vector_for_.push_back(loop_for);
    }

    if (regex_match(line, regex_while))
    {
      Loop loop_while(line, count_lines_, 2);
      vector_for_.push_back(loop_while);
    }

    if (regex_match(line, regex_main))
      main_ = true;

    if (regex_match(line, regex_comment_inline))
    {
      Comment comment(line, count_lines_);
      vector_comment_inline_.push_back(comment);
    }

    if (regex_match(line, regex_comment_block_ini))
    {
      if (count_lines_ == 1)
        description_ = true;

      Comment comment(line, count_lines_);

      while (!regex_match(line, regex_comment_block_end))
      {
        getline(input_file, line);
        comment.AddLine(line);
        count_lines_++;
      }
      comment.SetNumberLineEnd(count_lines_);
      vector_comment_block_.push_back(comment);
    }
  }
  input_file.close();
}


std::ostream &Analyzer::Write(std::ostream &os)
{
  os << "PROGRAM: " << namefile_input_ << std::endl;

  os << "DESCRIPTION: " << std::endl;

  if (description_)
    os << vector_comment_block_[0].GetComment() << std::endl;
  else
    os << "No description" << std::endl;

  os << "\nVARIABLES: " << std::endl;
  for (size_t i = 0; i < vector_int_.size(); i++)
    os << vector_int_[i] << std::endl;

  for (size_t i = 0; i < vector_double_.size(); i++)
    os << vector_double_[i] << std::endl;

  os << "\nSTATENMENTS: " << std::endl;
  for (size_t i = 0; i < vector_for_.size(); i++)
    os << vector_for_[i] << std::endl;

  for (size_t i = 0; i < vector_while_.size(); i++)
    os << vector_while_[i] << std::endl;

  os << "\nMAIN: " << std::endl;
  main_ ? (os << "True" << std::endl) : (os << "False") << std::endl;

  os << "\nCOMMENTS: " << std::endl;
  for (size_t i = 0; i < vector_comment_inline_.size(); i++)
    os << vector_comment_inline_[i] << std::endl;
  if (!description_)
    for (size_t i = 0; i < vector_comment_block_.size(); i++)
      os << vector_comment_block_[i] << std::endl;
  else
    for (size_t i = 1; i < vector_comment_block_.size(); i++)
      os << vector_comment_block_[i] << std::endl;
  return os;
}


std::ostream &operator<<(std::ostream &os, Analyzer &program)
{
  return program.Write(os);
}