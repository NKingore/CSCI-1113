#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player {
 private:
  std::string _name;
  int _side; //-1 is red, 1 is black
 public:
  Player();
  Player(std::string, int);
  std::string get_name();
  void set_side(int);
  int get_side();
};
#endif
