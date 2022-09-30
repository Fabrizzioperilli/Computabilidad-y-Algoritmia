// Universidad de la Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 1: Simbolos, alfabetos y cadena
// Autor: Fabrizzio Daniell Perilli Martin
// Correo: alu0101138589@ull.edu.es
// Fecha: 5/10/2022
// Archivo p01_strings.cc: programa cliente.
//             ...
// Referencias:
// Historial de revisiones:
// Fecha: 28/09/2022 - Versión: 1.0 - Descripción: Creación del código.

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include "../include/Symbol.h"
#include "../include/Alphabet.h"
#include "../include/Word.h"

void help();
void value(char *, char *, int);
std::vector<std::string> split(std::string, char);

int main(int argc, char *argv[])
{

    const std::string optionHelp = "--help";

    if (argc == 4)
    {
        std::cout << "Parametros correctos" << std::endl;
        int opcode = atoi(argv[3]);
        value(argv[1], argv[2], opcode);
    }
    else if ((argc == 2) && (argv[1] == optionHelp))
    {
        help();
        return -1;
    }
    else
    {
        std::cout << "Error al ejecutar." << std::endl;
        std::cout << "Ejecute ./p01_strings --help para mas informacion" << std::endl;
        return -1;
    }

    return 0;
}

void help()
{

    std::cout << "Modo de funcionamiento: " << std::endl;
    std::cout << "./p01_strings FicheroEntrada.txt FicheroSalida.txt NumeroOperacion" << std::endl;
    std::cout << "--Operaciones con cadenas" << std::endl;
    std::cout << "1 Longitud" << std::endl;
    std::cout << "2 Inversa" << std::endl;
    std::cout << "3 Prefijos" << std::endl;
    std::cout << "4 Sufijos" << std::endl;
    std::cout << "5 Subcadenas" << std::endl;
}

void value(char *fileInput, char *fileOutput, int opcode)
{

    std::string line;
    std::ifstream nameFileInput(fileInput);
    std::ofstream nameFileOutput(fileOutput);

    std::vector<std::string> auxLine;

    while (!nameFileInput.eof())
    {
        getline(nameFileInput, line);
        auxLine = split(line, ' ');

        Symbol symbol;
        for (size_t i = 0; i < auxLine.size() - 1; i++)
            symbol.add(auxLine[i]);
        
        Alphabet alphabet;
        alphabet.add(symbol);
        Word word(auxLine.back(), alphabet);
        
        // Cuando no se especifica el alfabeto
        if (alphabet.empty()){
            word.searchSymbol();
        }
    }
}




std::vector<std::string> split(std::string str, char pattern)
{

    int posInit = 0;
    int posFound = 0;
    std::string splitted;
    std::vector<std::string> results;

    while (posFound >= 0)
    {
        posFound = str.find(pattern, posInit);
        splitted = str.substr(posInit, posFound - posInit);
        posInit = posFound + 1;
        results.push_back(splitted);
    }

    return results;
}