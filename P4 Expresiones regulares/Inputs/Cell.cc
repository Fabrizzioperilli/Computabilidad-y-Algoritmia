/**
 * @details Universidad de La Laguna Escuela Superior de Ingenierıa y Tecnologıa
 *  Grado en Ingenierıa Informatica
 *  Asignatura: Algoritmos y Estructuras de Datos Avanzados
 *  Curso: 2º
 *  Practica 1: El juego de la vida
 * @author Fabrizzio Daniell Perilli Martin
 *   Correo: alu0101138589@ull.edu.es
 * @date Fecha entrega: 7/03/2021
 * @file Archivo: Cell.cc
 */

#include "../include/Grid.h"
#include "../include/Cell.h"

Cell::Cell(int i, int j)
{
  setPos(i, j);
}


State 
Cell::getState() const
{
  return state_;
}



std::pair<int, int>
Cell::getPos()
{
  return pos_;
}



int 
Cell::getnNeightborsLiving()
{
  return nNeightborsLiving_;
}



void 
Cell::setPos(std::pair<int, int> pos)
{
  pos_ = pos;
}



void 
Cell::setPos(int i, int j)
{
  pos_ = std::make_pair(i, j);
}



void 
Cell::setState(State &state)
{
  state_ = state;
}



void 
Cell::setnNeightborsLiving(int nNeighborsLiving)
{
  nNeightborsLiving_ = nNeighborsLiving;
}



void 
Cell::updateState()
{

  if (getState().getLiving() == 0)
  {
    if (getnNeightborsLiving() == 3)
      state_.setLiving(1);
    else
      state_.setLiving(0);
  }
  else
  {
    if ((getnNeightborsLiving() == 3) || ((getnNeightborsLiving() == 2)))
      state_.setLiving(1);
    else
      state_.setLiving(0);
  }
}



int 
Cell::neighbors(const Grid &grid)
{

  int nNeighbors = 0;
  for (int i = getPos().first - 1; i <= getPos().first + 1; i++)
    for (int j = getPos().second - 1; j <= getPos().second + 1; j++)
      if ((i != getPos().first) || (j != getPos().second))
        if (grid.getGrid()[i * grid.getColumn() + j]->getState().getLiving() == 1)
          nNeighbors++;

  setnNeightborsLiving(nNeighbors);
  return nNeightborsLiving_;
}



std::ostream 
&operator<<(std::ostream &os, const Cell &cell)
{

  if (cell.getState().getLiving())
    os << "█";
  else
    os << " ";

  return os;
}
/*fjsdjfijfiorgjoigr
gijsrgiojrsgiosg
goisrgjsog*/
///gdggjgio
