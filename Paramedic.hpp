#pragma once
#include "Soldier.hpp"
using namespace WarGame;
  class Paramedic: public WarGame::Soldier{
public:
  Paramedic(uint t);
  virtual void attack(Board* board, int row, int column);
  virtual void ParamedicCommanderSaysShoot(Board* board, int row, int column){attack(board, row, column);};

};
