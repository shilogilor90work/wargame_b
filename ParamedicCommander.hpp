#pragma once
#include "Soldier.hpp"
  class ParamedicCommander: public WarGame::Soldier{
public:
  ParamedicCommander(uint t);
  virtual void attack(WarGame::Board* board, int row, int column);

};
