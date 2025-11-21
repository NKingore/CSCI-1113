#include <string>
#include "player.h"

Player::Player(){
  _name = "John Doe";
  _side = -1; //-1 is red, 1 is black
}

Player::Player(std::string name, int side) {
  _name = name;
  _side = side;
}

std::string Player::get_name() {
  return _name;
}

void Player::set_side(int side) {
  _side = side;
}

int Player::get_side() {
  return _side;
}