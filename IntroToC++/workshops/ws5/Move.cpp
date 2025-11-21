#include <iostream>
#include <string>

#include "move.h"
using namespace std;

Move::Move(std::string spots, int ** board, Player player){ 
    int row, col;
    notation = spots;
    jump = 0;
//destination pointer are the last 3 spots that the player wants to move
//origin string is the first spot that the player enters during their move
//the main thing this constructor is checking if the isValid() variable is false. so set isValid() variable to true at the begining
    valid = true;
//then set the origin variable from my spots parameter
    origin = getOrigin(row, col);

    int size = spots.length() / 2 - 1;
    destinations = new std::string[size];   //this sets the size of destinations

//then set destinations using for loop
    for (int i = 0; i < size; i++){
      destinations[i] = spots.substr(2 + i*2, 2);
    };

    int start_row, start_col, move_row, move_col;
    getOrigin(start_row, start_col);
    int piece = board[start_row][start_col];

    for (int i = 0; i < size; i++){
        if (i == 0){
//this is the first move
            getDestination(i, move_row, move_col);
        }else {
//this is not the first move
            getDestination(i - 1, start_row, start_col);
            getDestination(i, move_row, move_col);
        }
        
        if (start_row - move_row != 1 && start_row - move_row != 2 && start_row - move_row != -1 && start_row - move_row != -2){
            valid = false;
        }

        if (start_col - move_col != 1 && start_col - move_col != 2 && start_col - move_col != -1 && start_col - move_col != -2){
            valid = false;
        }

        if (abs(start_row - move_row) != abs(start_col - move_col)){
            valid = false;
        }
        
        if (abs(start_row - move_row) == 2) {
            jump++;
        }
            
//check if you are moving your teams piece and not a blank spot or the other players piece
//are you moving to a valid spot? different for regular and kings
        int final_spot = board[move_row][move_col];
        if (player.get_side() == 1) {
//piece is black so piece = 1
            if (piece == 1){
//piece is regular
                if(jump != 0){
//then we are jumping
                    int middle_row, middle_col, middle_piece;
                    middle_row = ((start_row + move_row) / 2);
                    middle_col = ((start_col + move_col) / 2);
                    middle_piece = board[middle_row][middle_col];

                    if (middle_piece != -1 && middle_piece != -2){
                        //checks that the piece that was jumped was on the opposing team
                        valid = false;
                    }
                    if (getDestination(i, move_row, move_col) != 0){
                        //checks that the destination is an empty space
                        valid = false
                    }
                }
                //is the piece moving diagonally down left or right? 
                //is the spot its landing on open?
            }else if(piece == 2){
//piece is king
                if(jump != 0){
//the king is jumping
                    int middle_row, middle_col, middle_piece;
                    middle_row = ((start_row + move_row) / 2);
                    middle_col = ((start_col + move_col) / 2);
                    middle_piece = board[middle_row][middle_col];

                    if (middle_piece != -1 && middle_piece != -2){
                        //checks that the piece that was jumped was on the opposing team
                        valid = false;
                    }

                    if (getDestination(i, move_row, move_col) != 0){
                        //checks that the destination is an empty space
                        valid = false
                    }
                }
            }else {
                valid = false;
            }
        }else {
//piece is red
            if (piece == -1){
//piece is regular
                if(jump != 0) {
                    int middle_row, middle_col, middle_piece;
                    middle_row = ((start_row + move_row) / 2);
                    middle_col = ((start_col + move_col) / 2);
                    middle_piece = board[middle_row][middle_col];

                    if (middle_piece != -1 && middle_piece != -2){
                        //checks that the piece that was jumped was on the opposing team
                        valid = false;
                    }

                    if (getDestination(i, move_row, move_col) != 0){
                        //checks that the destination is an empty space
                        valid = false
                    }
                }
                //is the piece moving diagonally down left or right? 
                //is the spot its landing on open?
            }else if(piece == -2){
//piece is king
                if(jump != 0){
//king is jumping
                    int middle_row, middle_col, middle_piece;
                    middle_row = ((start_row + move_row) / 2);
                    middle_col = ((start_col + move_col) / 2);
                    middle_piece = board[middle_row][middle_col];

                    if (middle_piece != 1 && middle_piece != 2){
//checks that the piece that was jumped was on the opposing team
                        valid = false
                    }

                    if (getDestination(i, move_row, move_col) != 0){
//checks that destination is an empty space
                        valid = false
                    }
                }

                
            }else {
                valid = false;
            }
        }
    }
/*
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
    delete[] destinations;
    
}

bool Move::isValid() {
    return valid;
}
       
void Move::print() {
//print string::notation declared in move.h
    cout << notation << endl;
//print the origin using the origin variable
    cout << "You started at " << getOrigin(spots, spots) << "." << endl;
//Using for() loop to print the destination pointer
    for (int i = 0; i < jumps; i++){
        cout << "You moved " << destination[i] << endl;
    };
//print num many jumps using the jump variable
    cout << "You jumped: " << getJumps() << " times." << endl;
}       

int Move::getJumps() {
    //jump = spots.length() / 2 - 1;
    return jumps;
}

void Move::getOrigin(int & row, int & col){
//set the row and col using the origin variable
    char letter = origin.at(0);
    char num = origin.at(1);
    row = 8 - (num - '1') - 1;
    col = letter - 'A';
//origin string is the first spot that the player enters during their move
//*num and letter are char variables*
}

void Move::getDestination(int index, int & row, int & col){
    //the first parameter is the index of the destinations pointer
    //the other two parameters are row and col
    char letter = destinations[index].at(0);
    char num = destinations[index].at(1);
    row = 8 - (num - '1') - 1;
    col = letter - 'A';
    //*num and letter are char variables*
    //set row and col using the string at the index of destinations pointer
    //convert row and col of the board to the correct array index using the equation:
    //destinations pointer are the last 3 spots that the player wants to move
}
