/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 * @details Grado en Ingenierıa Informatica
 * @details Asignatura: Computabilidad y Algoritmia
 * @details Curso: 2º
 *          Practica 7: Gramtica regular a partir de DFA
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha: 15/11/2022
 * @file Archivo: grammar2CNF.cc  Programa cliente
 * Referencias:
 * @version Historial de revisiones:11/11/2022 - Versión: 1.0 - Descripción:
 * Creación del código.
 */

#include <iomanip>
#include <iostream>

#include "Grammar.h"

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
                   "./grammar2CNF --help para mas informacion" << std::endl;
      exit(EXIT_FAILURE);
    }
  } else if (argc == 2 && argv[1] == kOptionHelp)
    Help();
  else {
    std::cout << "Error en los parametros. Ejecute ./grammar2CNF --help para mas informacion" << std::endl;
    exit(EXIT_FAILURE);
  }

  return 0;
}


/// @brief Funcion que muestra la ayuda del programa
void Help() {
  std::cout << "\nModo de empleo: ./grammar2CNF input.gra output.gra"
            << std::endl;

  std::cout << "\nEl programa crea una gramática a partir de la especificacion dada en el\n"
               "fichero .gra y escribe el resultado de convertir una gramatica a Forma."
               "Normal de Chomsky" << std::endl;
}


/// @brief Comprueba que las extensiones de los ficheros sean correctas
/// @param file_fa
/// @param file_gra
/// @return bool
bool CheckExtension(std::string file_fa, std::string file_gra) {
  file_fa = file_fa.substr(file_fa.find_last_of(".") + 1);
  file_gra = file_gra.substr(file_gra.find_last_of(".") + 1);

  if (file_fa == "gra" && file_gra == "gra")
    return true;
  else
    return false;
}


/// @brief Lee los ficheros y crea el automata
/// @param file_fa
/// @param file_gra
void ReadFile(std::string input_file_gra, std::string output_file_gra) {

  std::ofstream output_file;

  Grammar grammar(input_file_gra);
  
  Alphabet alpha = grammar.GetAlphabet();
  std::set<Symbol> symbols = grammar.GetNonTerminalSymbols();
  Symbol start_symbol = grammar.GetStartSymbol();
  std::set<Production> productions = grammar.GetProductions();
  output_file.open(output_file_gra);

  if (output_file.is_open()) {
    // gramar.ConvertCNF()
    output_file << alpha << std::endl;
    for (auto i : symbols)
      output_file << i << std::endl;
    output_file << start_symbol << std::endl;
    
    for (auto i : productions)
      output_file << i << std::endl;
    
  } else {
    std::cout << "No se puede abrir el fichero" << output_file_gra << " o no existe" << std::endl;
    exit(EXIT_FAILURE);
  }

  output_file.close();
}
