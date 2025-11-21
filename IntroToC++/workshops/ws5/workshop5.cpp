#include <iostream>
using namespace std;



/*
1) board
2) red
3) black
4) piece_type
5) piece_num
6) piece_location
7) 
*/

class Board{
    //squares
        //spot
        //location
        //color
    //dimentions
        //8x8   
    //coordinate system 
        //chess coordinate system.
        /*
        8   -   -   -   -
        7 -   -   -   -  
        6   -   -   -   - 
        5 -   -   -   -  
        4   -   -   -   -
        3 -   -   -   -  
        2   -   -   -   -
        1 -   -   -   -  
          A B C D E F G H
        */
    //only plays on one color

};

class Piece{
    //num per player
        //12 pieces
    //type
        //"piece" or "checker" or "regular"
        //king
            //you become king by reaching other opposite side of the board
                //opposite side is the furthest row from the player
    //color
        //red
        //black
    //only one piece per square
    
};

class Game{
    //players take turns
    //1 move per turn
    //game over when one team runs out of pieces or when one play is blocked
    //setup
        //my pieces start on playable color squares in my first 3 rows 
        //who plays first
};

class Move{
    //can move Diagonally forward
        //one space
        //you can jump exactly one of your opponents pieces 1 or more times, over opponents piece
            //removes opponents piece when jumped
    //regular only moves diagonally forward
    //kings can move forward or backward
    //destination must be empty for every move
    //origin
    //destinaiton
        //must be on the board
    //players can only move your own pieces

};

class Player{
    //has a side
};