
#include "Board.hpp"
#include <iostream>

namespace WarGame {


  Soldier*& Board::operator[](std::pair<int,int> location)
  {
    return this->board[location.first][location.second];
  }
  Soldier* Board::operator[](std::pair<int,int> location) const
  {
    return this->board[location.first][location.second];
  }
  void Board::move(uint player_number, std::pair<int,int> source, Board::MoveDIR direction)
  {
    std::pair<int,int> target_spot = source; //{source.first, source.second};
    switch(direction) {
    case Up :
      target_spot.first ++;
      break;
    case Down :
      target_spot.first --;
      break;
    case Right :
      target_spot.second ++;
      break;
    case Left :
      target_spot.second --;
      break;
    };
    if (!(target_spot.first < 8 && target_spot.first >=0 && target_spot.second < 8 && target_spot.second >=0 &&
       this->board[target_spot.first][target_spot.second] == nullptr &&
       this->board[source.first][source.second] != nullptr &&
       this->board[source.first][source.second]->get_team() == player_number))
    {
      throw std::invalid_argument("Invalid syntax.");
    }
    // move
    this->board[target_spot.first][target_spot.second] = this->board[source.first][source.second];
    this->board[source.first][source.second] = nullptr;
    // attack
    this->board[target_spot.first][target_spot.second]->attack(this , target_spot.first, target_spot.second);
    // move soldier, and then attack using the soldier
  }
  bool Board::has_soldiers(uint player_number) const
  {
    for(int i=0; i<this->board.size(); i++)
    {
      for(int j=0; j<this->board[i].size(); j++)
      {
        if (this->board[i][j] != nullptr && this->board[i][j]->get_team() == player_number)
        {
          return true;
        }
      }
    }
    return false;
  }

}
