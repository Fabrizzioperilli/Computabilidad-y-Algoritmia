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
#include "Symbol.h"
#include "Alphabet.h"
#include "Word.h"

void help();
void read(char *, char *, int);
void write(std::ofstream &, std::vector<Word>, int);
std::vector<std::string> split(std::string, char);

int main(int argc, char *argv[])
{

    const std::string optionHelp = "--help";

    if (argc == 4)
    {
        int opcode = atoi(argv[3]);
        std::cout << "Ejecucion correcta. " << std::endl;
        std::cout << "Compruebe la salida en el fichero: " << argv[2] << std::endl;
        read(argv[1], argv[2], opcode);
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

void help() {
    std::cout << "Modo de funcionamiento: " << std::endl;
    std::cout << "./p01_strings FicheroEntrada.txt FicheroSalida.txt NumeroOperacion" << std::endl;
    std::cout << "--Operaciones con cadenas" << std::endl;
    std::cout << "1 Longitud" << std::endl;
    std::cout << "2 Inversa" << std::endl;
    std::cout << "3 Prefijos" << std::endl;
    std::cout << "4 Sufijos" << std::endl;
    std::cout << "5 Subcadenas" << std::endl;
}

void read(char *fileInput, char *fileOutput, int opcode)
{

    std::string line;
    std::ifstream nameFileInput(fileInput);
    std::ofstream nameFileOutput(fileOutput);

    std::vector<std::string> auxLine;
    std::vector<Word> aux;

    while (!nameFileInput.eof())
    {
        getline(nameFileInput, line);
        auxLine = split(line, ' ');

        Symbol symbol;
        for (size_t i = 0; i < auxLine.size() - 1; i++)
            if (auxLine[i] != STR_EMPTY)
                symbol.add(auxLine[i]);

        Alphabet alphabet;
        alphabet.add(symbol);
        Word word(auxLine.back(), alphabet);
        aux.push_back(word);

        if (symbol.empty())
        {
            std::cout << "El ultimo alfabeto es vacio " << std::endl;
        }

        std::cout << "Simbolos: ";
        symbol.write();

        std::cout << "\nAlfabeto:  ";
        alphabet.write();

        std::cout << "\nCadena: ";
        word.write();
        std::cout << std::endl;
    }
    nameFileInput.close();
    write(nameFileOutput, aux, opcode);
}


void write(std::ofstream &nameFileOutput, std::vector<Word> aux, int opcode)
{
    switch (opcode)
    {
    case 1:
        nameFileOutput << "Longitud de la cadena" << std::endl;
        for (size_t i = 0; i < aux.size(); i++)
            nameFileOutput << aux[i].wordLength() << std::endl;
        break;
    case 2:
        nameFileOutput << "Inversa de la cadena" << std::endl;
        for (size_t i = 0; i < aux.size(); i++)
            nameFileOutput << aux[i].wordInverse() << std::endl;
        break;
    case 3:
        nameFileOutput << "Prefijos de la cadena" << std::endl;
        for (size_t i = 0; i < aux.size(); i++)
            aux[i].wordPrefixes(nameFileOutput);
        break;
    case 4:
        nameFileOutput << "Sufijos de la cadena" << std::endl;
        for (size_t i = 0; i < aux.size(); i++)
            aux[i].wordSuffixes(nameFileOutput);
        break;
    case 5:
        nameFileOutput << "Subcadenas de la cadena" << std::endl;
        for (size_t i = 0; i < aux.size(); i++)
            aux[i].wordSubstrings(nameFileOutput);
        break;

    default:
        std::cout << "Error al ejecutar." << std::endl;
        std::cout << "Ejecute ./p01_strings --help para mas informacion" << std::endl;
        break;
    }
    nameFileOutput.close();
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