/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 *  Grado en Ingenierıa Informatica
 *  Asignatura: Algoritmos y Estructuras de Datos Avanzados
 *  Curso: 2º
 *  Practica 1: El juego de la vida
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha entrega: 7/03/2021
 * @file Archivo: Grid.cc
 */

#include "../include/Grid.h"

Grid::Grid(int n, int m, int nturns)
{
  assert(n >= 3 && m >= 3);
  n_ = n + 2;
  m_ = m + 2;
  grid_ = new Cell *[(n_) * (m_)];
  for (int i = 0; i < n_; i++)
    for (int j = 0; j < m_; j++)
      grid_[i * (m_) + j] = new Cell(i, j);

  setnTurn(nturns);
  menu();

  for (int i = 0; i < nTurn_; i++)
  {
    std::cout << "Turno[" << i + 1 << "]" << std::endl;
    write();
    nextGeneration();
  }
}


void 
Grid::menu()
{
  int nCell, op;

  std::cout << "Introduzca el número de células vivas que desea en el juego: ";
  std::cin >> nCell;
    if (nCell > (getRow()-2)*(getColumn()-2)){ 
        std::cout << "El número de células es mayor que las cuadriculas del tablero" << std::endl;
          exit(EXIT_FAILURE);
    }
  std::cout << "\nGenerar coordenadas aleatorias. 0" << std::endl;
  std::cout << "Introducir coordenadas manualmente. 1" << std::endl;
  std::cout << "Seleccione una opción: ";
  std::cin >> op;

  State state(1);

  if (op == 0)
  {
    int x[n_*m_], y[n_*m_];
    srand(time(NULL));
    std::cout << "Células creadas: " << std::endl;
    for (int i = 1; i <= nCell; i++)
    {
      x[i] = 1 + rand() % (getRow() - 2);
      y[i] = 1 + rand() % (getColumn() - 2);
      std::cout << "["<< i << "]: "<<"x: " << x[i] << ", y: " << y[i] << std::endl;
      grid_[x[i] * getColumn() + y[i]]->setState(state);
    }
  }
  else if (op == 1)
  {
    int x, y;
    std::cout << "Introduzca las coordenadas en el tablero de cada una de las células:" << std::endl;
    for (int i = 1; i <= nCell; i++)
    {
      std::cout << "Célula[" << i << "]-(x>0): ";
      std::cin >> x;
       
       if(x > getRow()-2 || x < 1){
          std::cout << "La posición es incorrecta dentro del tablero" << std::endl;
          exit(EXIT_FAILURE);
        }
     
      std::cout << std::setw(15) << "(y>0): ";
      std::cin >> y;
        
        if(y > getColumn()-2 || y < 1){
          std::cout << "La posición es incorrecta" << std::endl;
          exit(EXIT_FAILURE);
        }
      std::cout << "--------------" << std::endl;
      grid_[x * getColumn() + y]->setState(state);
    }
  }

  else
  {
    std::cout << "Introduzca una opción válida" << std::endl;
    exit(EXIT_FAILURE);
  }
}



void 
Grid::nextGeneration()
{

  for (int i = 1; i < getRow() - 1; i++)
    for (int j = 1; j < getColumn() - 1; j++)
      grid_[i * getColumn() + j]->neighbors(*this);

  for (int i = 1; i < getRow() - 1; i++)
    for (int j = 1; j < getColumn() - 1; j++)
      grid_[i * getColumn() + j]->updateState();
}



void
Grid::write()
{

  for (int i = 1; i < getRow() - 1; i++)
  {
    for (int j = 1; j < getColumn() - 1; j++)
      std::cout << "  " << *grid_[i * getColumn() + j] << "|";
    std::cout << std::endl;
  }
    sleep(1);
}



int 
Grid::getRow() const
{
  return n_;
}



int 
Grid::getColumn() const
{
  return m_;
}



int 
Grid::getnTurn()
{
  return nTurn_;
}



Cell **Grid::getGrid() const
{
  return grid_;
}



void 
Grid::setRow(int row)
{
  n_ = row;
}



void
Grid::setColumn(int col)
{
  m_ = col;
}



void 
Grid::setnTurn(int turns)
{
  nTurn_ = turns;
}



void 
Grid::setGrid(Cell **grid)
{
  grid_ = grid;
}



