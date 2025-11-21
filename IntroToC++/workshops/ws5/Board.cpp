#include <iostream>
#include <cmath> //for abs()
#include "board.h"
#include "move.h"

using namespace std;

Board::Board() {
  //cout << "_board_positions init" << endl;
  _board_positions = new int*[8];
  //cout << "_board_positions[i] init" << endl;
  for (int i = 0; i < 8; i++) {
	_board_positions[i] = new int[8];  
  }
  
  //cout << "_board_positions[i][j] = 0" << endl;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
	  _board_positions[i][j] = 0;
	}
  }
  
  //cout << "_board_positions place red/black" << endl;
  for (int i = 0; i < 8; i+=2) {
    _board_positions[1][i] = 1;
	_board_positions[5][i] = -1;
	_board_positions[7][i] = -1;
  }
  for (int i = 1; i < 8; i+=2) {
    _board_positions[0][i] = 1;
	_board_positions[2][i] = 1;
	_board_positions[6][i] = -1;
  }
  
  //cout << "set rendering strings" << endl;
  /* 2x2 squares
  _horiz_board_border_render = " +--+--+--+--+--+--+--+--+";
  _file_labels_render =        "   a  b  c  d  e  f  g  h ";
  _empty_half_square_render = "  |";
  _red_half_square_render =   "##|";*/
  
  _horiz_board_border_render = " +---+---+---+---+---+---+---+---+";
  _file_labels_render =        "    a   b   c   d   e   f   g   h ";
  _empty_half_square_render = "   |";
  _red_half_square_render =   "###|";
  
  //cout << "constructor complete" << endl;
}

Board::~Board() {
  delete[] _board_positions;
}

void Board::print() {
  //even rows => black squares have even index, red squares have odd index
  //odd rows => red squares have even index, red squares have odd index
  //red squares => row % 2 + col % 2 == 1
  //black squares => row % 2 + col % 2 != 1 (equals 0 or 2)
  for (int i = 0; i < 8; i++) {
    cout << _horiz_board_border_render << endl;
	cout << " "; //no rank label on top half
	cout << "|"; //left border
    for (int j = 0; j < 8; j++) { //top half of square
	  
	  if (((i % 2) + (j % 2)) != 1) {
		  //red square, just print the red
		  cout << _red_half_square_render;
		  //cout << i << j << "|";
	  } else {
		  switch(_board_positions[i][j]) {
		    case -2: cout << "RRR|"; break;
			case -1: 
			case 0:  
			case 1:  cout << "   |"; break;
			case 2:  cout << "BBB|"; break;
			default: cout << "???|"; break; //just in case
		  }
	  }
	}
	cout << endl;
	cout << (8-i); //rank label
	cout << "|";
	for (int j = 0; j < 8; j++) { //bottom half of square
	  
	  if (((i % 2) + (j % 2)) != 1) {
		  cout << _red_half_square_render;
	  } else {
		  switch(_board_positions[i][j]) {
		    case -2: cout << "RRR|"; break;
			case -1: cout << "rrr|"; break;
			case 0:  cout << "   |"; break;
			case 1:  cout << "bbb|"; break;
			case 2:  cout << "BBB|"; break;
			default: cout << "???|"; break; //just in case
		  }
		  //cout << i << j << _board_positions[i][j];
	  }
	}
	cout << endl;
  }
  cout << _horiz_board_border_render << endl;
  cout << _file_labels_render << endl;
  /*cout << "-----DEBUG-----" << endl;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
	  cout << _board_positions[i][j] << " ";
	}
	cout << endl;
  }*/
}

bool Board::make_move(string move, Player mover) {
	Move player_move(move, _board_positions, mover);
	if (player_move.isValid()) {
		std::cout << "DEBUG::";
		player_move.print();
		int prior_row,prior_col,destination_index=0;
		player_move.getOrigin(prior_row, prior_col);
		
		int attempt_row, attempt_col;
		player_move.getDestination(destination_index, attempt_row, attempt_col);

		int original_piece = _board_positions[prior_row][prior_col];
		
		//empty source location
		_board_positions[prior_row][prior_col] = 0;
		
		int jumps_made = 0;
		
		if (jumps_made < player_move.getJumps()) {
			_board_positions[(prior_row+attempt_row)/2][(prior_col+attempt_col)/2] = 0;
			jumps_made++;
		}
		
		while (jumps_made < player_move.getJumps()) {
			destination_index++;
			prior_row = attempt_row;
			prior_col = attempt_col;
			player_move.getDestination(destination_index, attempt_row, attempt_col);
			_board_positions[(prior_row+attempt_row)/2][(prior_col+attempt_col)/2] = 0;
			jumps_made++;
		}
		
		//in the end, place the piece on its new square
		_board_positions[attempt_row][attempt_col] = original_piece;
		
		
		//CHECK TO MAKE KING!!!
		
		if (attempt_row == 7 && mover.get_side() == 1) {
			_board_positions[attempt_row][attempt_col] = 2;
		}
		if (attempt_row == 0 && mover.get_side() == -1) {
		  _board_positions[attempt_row][attempt_col] = -2;
		}
	}
	else {
		cout << "Invalid move!" << endl;
	}
	return true;
}


void Board::set_position(int code) {
	switch(code) {
		case 1:
		  for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
			  _board_positions[i][j] = 0;
			}
		  }
		  _board_positions[7][0] = -1;
		  _board_positions[6][1] = 1;
		  _board_positions[4][1] = 1;
		  _board_positions[2][1] = 1;
		  
		break;
		
		default: break; // do nothing if wrong code
	}
}
