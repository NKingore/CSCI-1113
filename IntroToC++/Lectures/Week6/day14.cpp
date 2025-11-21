#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(time(0));

    const int MAP_ROWS = 10, MAP_COLS = 20, NUM_TREES = 10;
    char gameMap[MAP_ROWS][MAP_COLS];

    for(int i = 0; i < MAP_ROWS; i++) {
        for(int j = 0; j < MAP_COLS; j++){
            gameMap[i][j] = 'E'; // 'E' for empty
        }
    }

    //RANDOMLY PLACE NUM_TREE number of TREES
    for(int i = 0; i < NUM_TREES; i++) {
        gameMap[rand() % MAP_ROWS][rand() % MAP_COLS] = 'T'; // 'T' for tree
    }

    int player_y = rand() % MAP_ROWS;
    int player_x = rand() % MAP_COLS;
    gameMap[player_y][player_x] = 'P'; //'P' for player

    for (int i = 0; i < MAP_ROWS; i++){
        for (int j = 0; j < MAP_COLS; j++) {
            switch(gameMap[i][j]){
                case 'E': std::cout << "_ "; break;
                case 'T': std::cout << "^ "; break;
                case 'P': std::cout << "P "; break;
                default: std::cout << "! ";
            }
        }
        std::cout << std::endl;
    }

    
    char u_in;
    std::cout << "Enter a direction (N, E, S, W) or 'X' to exit: " << std::endl;
    std::cin >> u_in;

    while (u_in != 'X') {

        gameMap[player_y][player_x] = 'E';

        switch(u_in) {
            case 'N': 
                if (player_x > 0) player_y--; break;
            case 'n':  
                if (player_x > 0) player_y--; break;
            case 'W': 
                if (player_y > 0) player_x--; break;
            case 'w': 
                if (player_y > 0) player_x--; break;
        }
        std::cout << "Enter a direction (N, E, S, W) or 'X' to exit: " << std::endl;
        std::cin >> u_in;
    
    }
}

