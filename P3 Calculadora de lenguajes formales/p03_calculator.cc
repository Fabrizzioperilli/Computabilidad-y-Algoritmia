// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Calculadora de  lenguajes formales
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 18/10/2022
// Archivo: p03_calculator.cc Programa cliente
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 12/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>

#include "Alphabet.h"
#include "Language.h"
#include "Symbol.h"
#include "Word.h"
#include "Rpn.h"

void Help();
void Read(char *);
void Split(std::string, int);
Language CheckLanguage(std::string);
std::vector<std::string> Operation(std::string);
void Calculate(std::vector<Language>, std::vector<std::vector<std::string>>);

int main(int argc, char **argv)
{
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 2;

  if ((argc == kNumberParam) && (argv[1] != kOptionHelp))
  {
    std::cout << "Lectura del fichero: " << argv[1] << std::endl;
    Read(argv[1]);
  }
  else if ((argc == kNumberParam) && (argv[1] == kOptionHelp))
  {
    Help();
    return -1;
  }
  else
  {
    std::cout << "Error al ejecutar." << std::endl;
    std::cout << "Ejecute ./p02_languages --help para mas informacion" << std::endl;
    return -1;
  }
  return EXIT_SUCCESS;
}

void Help()
{
  std::cout << "Modo de funcionamiento: " << std::endl;
  std::cout << "./p03_calculadora FicheroEntrada.txt " << std::endl;
  std::cout << "---Operaciones con lenguajes---" << std::endl;
  std::cout << " + Concatenacion" << std::endl;
  std::cout << " | Union" << std::endl;
  std::cout << " ^ Interseccion" << std::endl;
  std::cout << " - Diferencia" << std::endl;
  std::cout << " ! Inversa" << std::endl;
  std::cout << " * Potencia" << std::endl;
}


void Read(char *file_input)
{
  std::string line;
  std::ifstream namefile(file_input);
  Language language;
  std::vector<Language> vector_language;
  std::vector<std::string> operation;
  std::vector<std::vector<std::string>> vector_operation;
  std::vector<Language> vector_result;

  while (!namefile.eof())
  {
    getline(namefile, line);
    Language language = CheckLanguage(line);
    operation = Operation(line);
    
    if (!language.Empty())
      vector_language.push_back(language);

    if (!operation.empty())
      vector_operation.push_back(operation);
  }

  Rpn rpn;
  vector_result = rpn.Calculate(vector_language, vector_operation);
  std::cout << "\n---Lenguaje resultado: " << std::endl;
  for (size_t i = 0; i < vector_result.size(); i++)
    std::cout << "Operacion: " << i + 1 << ": " << vector_result[i] << std::endl;
  
  

  namefile.close();
}


Language CheckLanguage(std::string line)
{
  Alphabet alphabet;
  std::set<Word> aux;
  int pos_ini = 0;
  for (size_t i = 0; i < line.length(); i++)
    if (line[i - 1] == ' ' && line[i] == '=' && line[i + 1] == ' ')
    {
      pos_ini = i + 2;
      std::vector<std::string> vector;
      std::string aux_string;

      for (size_t i = pos_ini; i < line.length(); i++)
      {
        if (line[i] != ' ' && line[i] != '{' && line[i] != '}' && line[i] != ',')
          aux_string += line[i];
        else if (line[i] == ' ' && line[i -1] == '{' && line[i + 1] == '}') 
          aux_string += line[i];
        else if (aux_string != "")
        {
          vector.push_back(aux_string);
          aux_string = "";
        }
      }
      for (size_t i = 0; i < vector.size(); i++)
      {
        Word word(vector[i], alphabet);
        aux.insert(word);
      }
    }
  Language language(aux, alphabet);
  return language;
}


std::vector<std::string> Operation(std::string line)
{
  std::vector<std::string> vector;
  std::string operation;
  for (size_t i = 0; i < line.length(); i++)
  {
    //Separar los operadores y los operandos en posiciones diferentes del vector
    if (line[i] == '+' || line[i] == '|' || line[i] == '^' || line[i] == '-' || line[i] == '!' || line[i] == '*')
    {
      
      operation += line[i];
      vector.push_back(operation);
      operation = "";
    }
    
    else if (line[i] == 'L' && line[i+3] != '=')
    {
      operation += line[i + 1];
      vector.push_back(operation);
      operation = "";
    }
  }
  
  return vector;
}