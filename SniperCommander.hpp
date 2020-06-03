#pragma once

#include "Soldier.hpp"
  class SniperCommander: public WarGame::Soldier{
public:
  SniperCommander(uint t);
  virtual void attack(WarGame::Board* board, int row, int column);
};
