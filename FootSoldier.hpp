#pragma once
#include "Soldier.hpp"
using namespace WarGame;
  class FootSoldier: public WarGame::Soldier{
public:
  FootSoldier(uint t);
  virtual void attack(Board* board, int row, int column);
  virtual void FootCommanderSaysShoot(Board* board, int row, int column){attack(board, row, column);};

};
