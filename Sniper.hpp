#pragma once
#include "Soldier.hpp"
using namespace WarGame;
  class Sniper: public WarGame::Soldier{
public:
  Sniper(uint t);
  virtual void attack(Board* board, int row, int column);
  virtual void SniperCommanderSaysShoot(Board* board, int row, int column){attack(board, row, column);};

};
