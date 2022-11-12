/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: dfa2grammar.cc  Programa cliente
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include <iomanip>
#include <iostream>

#include "Automata.h"

void Help();
bool CheckExtension(std::string, std::string);
void ReadFile(std::string, std::string);

int main(int argc, char **argv) {
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 3;

  if (argc == kNumberParam) {
    if (CheckExtension(argv[1], argv[2])) {
      ReadFile(argv[1], argv[2]);
      std::cout << "Revise la salida en el fichero: " << argv[2] << std::endl;
    } else {
      std::cout << "Las extensiones de los ficheros no son correctas. Ejecute "
                   "./dfa2grammar --help para mas informacion" << std::endl;
      exit(EXIT_FAILURE);
    }
  } else if (argc == 2 && argv[1] == kOptionHelp)
    Help();
  else {
    std::cout << "Error en los parametros. Ejecute ./dfa2grammar --help para mas informacion" << std::endl;
    exit(EXIT_FAILURE);
  }

  return 0;
}


/// @brief Funcion que muestra la ayuda del programa
void Help() {
  std::cout << "\nModo de empleo: ./dfa2grammar input.fa output.gra"
            << std::endl;

  std::cout << "\nEl programa crea un automata a partir de la especificacion dada en el\n"
               "fichero .fa y escribe el resultado de convertir un dfa en en una gramatica\n"
               "a través de fichero de configuración." << std::endl;
}


/// @brief Comprueba que las extensiones de los ficheros sean correctas
/// @param file_fa
/// @param file_gra
/// @return bool
bool CheckExtension(std::string file_fa, std::string file_gra) {
  file_fa = file_fa.substr(file_fa.find_last_of(".") + 1);
  file_gra = file_gra.substr(file_gra.find_last_of(".") + 1);

  if (file_fa == "fa" && file_gra == "gra")
    return true;
  else
    return false;
}


/// @brief Lee los ficheros y crea el automata
/// @param file_fa
/// @param file_gra
void ReadFile(std::string file_fa, std::string file_gra) {
  std::ifstream input_file_fa;
  std::ofstream output_file_gra;

  input_file_fa.open(file_fa);
  output_file_gra.open(file_gra);

  if (output_file_gra.is_open()) {
    Automata automata(file_fa);
    Grammar grammar = automata.ConvertToGrammar();
    output_file_gra << grammar;
  } else {
    std::cout << "No se puede abrir el fichero" << file_fa << " o no existe" << std::endl;
    exit(EXIT_FAILURE);
  }

  output_file_gra.close();
}
