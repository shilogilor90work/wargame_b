#pragma once
#include "Soldier.hpp"
  class FootCommander: public WarGame::Soldier{
public:
  FootCommander(uint t);
  virtual void attack(WarGame::Board* board, int row, int column);

};
