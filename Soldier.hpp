#pragma once

#include <stdexcept>
namespace WarGame {
  class Board;
  class Soldier{
public:
  uint team;
  int health;
  int damage;
  int original_health;
  Soldier(uint t);
  virtual void attack(Board* board, int row, int column)=0;
  uint get_team(){return team;}
  virtual void FootCommanderSaysShoot(Board* board, int row, int column){}
  virtual void SniperCommanderSaysShoot(Board* board, int row, int column){}
  virtual void ParamedicCommanderSaysShoot(Board* board, int row, int column){}

};
}
