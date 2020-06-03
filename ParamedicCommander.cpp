#include "ParamedicCommander.hpp"
#include "Board.hpp"
#include "Paramedic.hpp"

  ParamedicCommander::ParamedicCommander(uint t): Soldier(t)
  {
    this->health = 200;
    this->damage = 0;
    this->original_health = 200;
  }
  void ParamedicCommander::attack(Board* board, int row, int column)
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
    for(int i=0; i<board->board.size(); i++)
    {
      for(int j=0; j<board->board[i].size(); j++)
      {
        if (board->board[i][j] != nullptr && board->board[i][j]->get_team() == this->team)
        {
          board->board[i][j]->ParamedicCommanderSaysShoot(board, i, j);
        }
      }
    }
  }
