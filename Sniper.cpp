#include "Sniper.hpp"
#include "Board.hpp"


  Sniper::Sniper(uint t): Soldier(t)
  {
    this->health = 100;
    this->damage = 50;
    this->original_health = 100;
  }
  void Sniper::attack(Board* board , int row, int column)
  {
    int most_health = 0;
    Soldier* opponent = nullptr;
    int opponent_row;
    int opponent_column;
    for(int i=0; i<board->board.size(); i++)
    {
      for(int j=0; j<board->board[i].size(); j++)
      {
        if (board->board[i][j] != nullptr && board->board[i][j]->get_team() != this->team &&  board->board[i][j]->health > most_health)
        {
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
