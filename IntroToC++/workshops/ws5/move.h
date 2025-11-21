#ifndef MOVE_H
#define MOVE_H

#include "Player.h"

class Move {
    private:
        std::string origin;
        //std::string final_destination;
        std::string * destinations;
        int jumps;
        std::string notation;
        bool valid;

    public:
        Move(std::string, int **, Player);
        ~Move();
        bool isValid();
        void print();
        int getJumps();
        void getOrigin(int &, int &);
        void getDestination(int, int &, int &);
        //void getFinalDestination(int &, int &);

    /*
        attempt_col = <index_of<letter_in_origin> - 97;
        attempt_row = 8 - (static_cast<int>(index_of_number_in_origin) - 48);
    */


};


#endif