
#include "FootSoldier.hpp"
#include "Board.hpp"


  FootSoldier::FootSoldier(uint t): Soldier(t)
  {
    this->health = 100;
    this->damage = 10;
    this->original_health = 100;
  }
  void FootSoldier::attack(Board* board , int row, int column)
  {
    int distance = 9999999;
    Soldier* opponent = nullptr;
    int opponent_row;
    int opponent_column;
    for(int i=0; i<board->board.size(); i++)
    {
      for(int j=0; j<board->board[i].size(); j++)
      {
        if (board->board[i][j] != nullptr && board->board[i][j]->get_team() != this->team && (abs(row - i) + abs(column-j)) < distance)
        {
          distance = (abs(row - i) + abs(column-j));
          opponent = board->board[i][j];
          opponent_row = i;
          opponent_column = j;
        }
      }
    }

    if (opponent == nullptr){return;}
    opponent->health -= damage;
    if (opponent->health <= 0)
    {
      (*board)[{opponent_row,opponent_column}] = nullptr;
    }
  }
