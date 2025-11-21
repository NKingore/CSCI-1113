#include <iostream>
#include <string>

#include "move.h"

Move::Move(std::string spots, int ** board, Player player){ 
    /*
    notation = spots;
    jump = 0;
    destination pointer are the last 3 spots that the player wants to move
    origin string is the first spot that the player enters during their move
    the main thing this constructor is checking if the isValid() variable is false. so set isValid() variable to true at the begining
    then set the origin variable from my spots parameter
    size = spots.length() / 2 - 1;
    destinations = new std::string[size];   this sets the size of destinations
    then set destinations using for loop
    for (int i = 0, i < size, i++){
      destinations[i] = spots.substr(2 + i*2, 2)
    }

    int start_row, start_col, move_row, move_col;
    getOrigin(start_row, start_col);
    int piece = board[start_row][start_col];

    for (int i = 0; i < size; i++){
        if (i == 0){
            this is the first move
            getDestination(i, move_row, move_col);
        }else {
            getDestination(i - 1, start_row, start_col);
            getDestination(i, move_row, move_col);
        }
        
        if (start_row - move_row != 1 && start_row - move_row != 2 && start_row - move_row != -1 && start_row - move_row != -2){
            isValid() = false;
        }

        if (start_col - move_col != 1 && start_col - move_col != 2 && start_col - move_col != -1 && start_col - move_col != -2){
            isValid() = false;
        }

        if (abs(start_row - move_row) != abs(start_col - move_col)){
            isValid() = flase;
        }
        
        if (abs(start_row - move_row) == 2) {
            jump++;
        }
            
check if you are moving your teams piece and not a blank spot or the other players piece
are you moving to a valid spot? different for regular and kings
    
    
    int final_spot = board[move_row][move_col];

        if (player.get_side() == 1) {
            piece is black so piece = 1
            if (peice == 1){
                piece is regular

                if(jump != 0){
                    then we are jumping

                    int middle_row, middle_col, middle_piece;
                    middle_row = ((start_row + move_row) / 2);
                    middle_col = ((start_col + move_col) / 2);
                    middle_piece = board[middle_row, middle_col];

                    if (middle_piece != -1 && middle_piece != -2){
                        isValid() = false;
                    }
                }
                is the piece moving diagonally down left or right? 
                is the spot its landing on open?
            }else if(piece == 2){
                piece is king

            }else {
                isValid() = false;
            }
        }else {
            piece is red
            if (peice == -1){

                is the piece moving diagonally down left or right? 
                is the spot its landing on open?
            }else if(piece == -2){
            
            }else {
            isValid() = false;
            }
        }
    }

values of each piece and color and empty space
lowercase are regular, capital is king, empty is empty
    switch(_board_positions[i][j]) {
		    case -2: cout << "RRR|"; break;
			case -1: cout << "rrr|"; break;
			case 0:  cout << "   |"; break;
			case 1:  cout << "bbb|"; break;
			case 2:  cout << "BBB|"; break;
			default: cout << "???|"; break; //just in case
		  }

    
    
    
    */
}
        
Move::~Move() {
    //Delete[] the destinations pointer
    
}

bool Move::isValid() {
    //return the valid bool variable
}
       
void Move::print() {
    //print string::notation declared in move.h
    //print the origin using the origin variable
    //Using for() loop to print the destination pointer
    //print many jumps using the jump variable
}       

int Move::getJumps() {
    //return the jump variable
}

void Move::getOrigin(int & row, int & col){
    //set the row and col using the origin variable
    //row = 8 - (num - '0'); 
    //col = letter - 'a';                 *num and letter are char variables*
    //letter = origin.at(0);
    //num = origin.at(1);
}

void Move::getDestination(int index, int & row, int & col){
    //the first parameter is the index of the destinations pointer
    //the other two parameters are row and col
    //set row and col using the string at the index of destinations pointer
    //convert row and col of the board to the correct array index using the equation:
    //row = 8 - (num - '0'); 
    //col = letter - 'a';                 *num and letter are char variables*
    //letter = destinations[index].at(0);
    //num = destinations[index].at(1);
    //destinations pointer are the last 3 spots that the player wants to move
    //origin string is the first spot that the player enters during their move

}
