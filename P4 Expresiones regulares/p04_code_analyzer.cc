// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 4: Expresiones Regulares
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 25/10/2022
// Archivo: p04_code_analyzer.cc Programa cliente
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 20/10/2022 - Versión: 1.0 - Descripción: Creación del código.

#include "Analyzer.h"
#include <iostream>
bool CheckExtension(std::string);
void Help();

int main(int argc, char **argv) {
  const std::string kOptionHelp = "--help";
  const int kNumberParam = 3;

  if (argc == kNumberParam) {
    std::string namefile_input(argv[1]);
    std::ofstream file_output(argv[2]);

    if (!CheckExtension(namefile_input)) {
      std::cout << "Error en el fichero de entrada, introduzca un fichero con extensión .cc" << std::endl;
      return EXIT_FAILURE;
    }

    Analyzer analyzer(namefile_input);
    analyzer.Check();
    file_output << analyzer;
    std::cout << "Compruebe la salida en el fichero: " << argv[2] << std::endl;

  } else if ((argc == 2) && (argv[1] == kOptionHelp)) {
    Help();
    return EXIT_FAILURE;
  } else {
    std::cout << "Error en los parametros." << std::endl;
    std::cout << "Introduce ./p04_code_analyzer --help para más información" << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}


bool CheckExtension(std::string file) {
  if (file.substr(file.find_last_of(".") + 1) == "cc")
    return true;
  else
    return false;
}


void Help() {
  std::cout << "Modo de funcionamiento:" << std::endl;
  std::cout << "./p04_code_analyzer Inputs/fichero_entrada.cc fichero_salida.txt" << std::endl;
}