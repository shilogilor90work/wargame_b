#include "Paramedic.hpp"
#include "Board.hpp"


  Paramedic::Paramedic(uint t): Soldier(t)
  {
    this->health = 100;
    this->damage = 0;
    this->original_health = 100;
  }
  void Paramedic::attack(Board* board , int row, int column)
  {
    if (row<7 && board->board[row+1][column] != nullptr && board->board[row+1][column]->get_team() == this->team)
    {
      board->board[row+1][column]->health = board->board[row+1][column]->original_health;
    }
    if (row>0 && board->board[row-1][column] != nullptr && board->board[row-1][column]->get_team() == this->team)
    {
      board->board[row-1][column]->health = board->board[row-1][column]->original_health;
    }
    if (column<7 && board->board[row][column+1] != nullptr && board->board[row][column+1]->get_team() == this->team)
    {
      board->board[row][column+1]->health = board->board[row][column+1]->original_health;
    }
    if (column>0 && board->board[row][column-1] != nullptr && board->board[row][column-1]->get_team() == this->team)
    {
      board->board[row][column-1]->health = board->board[row][column-1]->original_health;
    }
  }
