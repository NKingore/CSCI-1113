#ifndef BOARD_H
#define BOARD_H

#include <string>
#include "player.h"

class Board {
 private:
  int ** _board_positions;
  std::string _horiz_board_border_render;
  std::string _empty_half_square_render;
  std::string _red_half_square_render;
  std::string _file_labels_render;
  
	
 public:
  Board();
  ~Board();
  void print();
  //bool validate_move(std::string, Player);
  bool make_move(std::string, Player);
  void set_position(int);
	
};
#endif
