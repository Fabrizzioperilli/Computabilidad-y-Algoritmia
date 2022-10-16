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

#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

#include "Alphabet.h"
#include "Language.h"
#include "Rpn.h"
#include "Symbol.h"
#include "Word.h"

void Help();
void Read(char *);
Language CheckLanguage(std::string);
std::vector<std::string> Operation(std::string);


int main(int argc, char **argv) {
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 2;

  if ((argc == kNumberParam) && (argv[1] != kOptionHelp)) {
    std::cout << "Lectura del fichero: " << argv[1] << std::endl;
    std::cout << "\n--Calculadora de Lenguajes formales-- " << std::endl;
    Read(argv[1]);
  } else if ((argc == kNumberParam) && (argv[1] == kOptionHelp)) {
    Help();
    return -1;
  } else {
    std::cout << "Error al ejecutar." << std::endl;
    std::cout << "Ejecute ./p02_languages --help para mas informacion" << std::endl;
    return -1;
  }
  return EXIT_SUCCESS;
}


void Help() {
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


void Read(char *file_input) {
  std::string line;
  std::ifstream namefile(file_input);
  Language language;
  std::vector<Language> vector_language;
  std::vector<std::string> operation;
  std::vector<std::vector<std::string>> vector_operation;
  std::vector<Language> vector_result;

  while (!namefile.eof()) {
    getline(namefile, line);
    Language language = CheckLanguage(line);

    if (!language.Empty())
      vector_language.push_back(language);

    operation = Operation(line);
    if (!operation.empty())
      vector_operation.push_back(operation);
  }

  std::cout << "Lenguajes:" << std::endl;
  for (size_t i = 0; i < vector_language.size(); i++)
    std::cout << vector_language[i].GetName() << " = " << "{ "<< vector_language[i] << "}"<<std::endl;

  std::cout << "\nOperaciones:" << std::endl;
  for (size_t i = 0; i < vector_operation.size(); i++) {
    for (size_t j = 0; j < vector_operation[i].size(); j++)
      std::cout << vector_operation[i][j] << " ";
  std::cout << std::endl;
  }
    
  Rpn rpn;
  vector_result = rpn.Calculate(vector_language, vector_operation);
  std::cout << "\nResultados: " << std::endl;
  for (size_t i = 0; i < vector_result.size(); i++)
    std::cout << "Operacion: " << i + 1 << ": { " << vector_result[i] << "}" <<std::endl;

  namefile.close();
}


Language CheckLanguage(std::string line) {
  std::string name_language;
  Alphabet alphabet;
  std::set<Word> aux;
  int pos_ini = 0;
  for (size_t i = 0; i < line.length(); i++)
    if (line[i - 1] == ' ' && line[i] == '=' && line[i + 1] == ' ') {
      pos_ini = i + 2;
      std::vector<std::string> vector;
      std::string aux_string;

      // Almacena el nombre del lenguaje
      for (size_t j = 0; j < i - 1; j++)
        name_language += line[j];

      for (size_t i = pos_ini; i < line.length(); i++) {
        if (line[i] != ' ' && line[i] != '{' && line[i] != '}' && line[i] != ',')
          aux_string += line[i];
        // Caso para la cadena vacia
        else if (line[i] == ' ' && line[i - 1] == '{' && line[i + 1] == '}')
          aux_string += line[i];
        else if (aux_string != "") {
          vector.push_back(aux_string);
          aux_string = "";
        }
      }
      for (size_t i = 0; i < vector.size(); i++) {
        Word word(vector[i], alphabet);
        aux.insert(word);
      }
    }

  Language language(aux, alphabet);
  language.SetName(name_language);
  return language;
}


std::vector<std::string> Operation(std::string line) {
  std::vector<std::string> vector;
  std::string operation;
  if (line.back() != '}') {
    for (size_t i = 0; i < line.length(); i++) {
      if (line[i] == '+' || line[i] == '|' || line[i] == '^' || line[i] == '-' || line[i] == '!' || line[i] == '*') {
        operation += line[i];
        vector.push_back(operation);
        operation = "";
      } else if (line[i] != ' ') 
        operation += line[i];
       else if (isdigit(line[i])) 
        operation += line[i];
       else if (operation != "") {
        vector.push_back(operation);
        operation = "";
      }
    }
  }

  return vector;
}