#include <iostream>
using namespace std;

//declare constants
const int BOARD_SIZE = 9;
const int GRID = 3;

//starting board
int board[BOARD_SIZE][BOARD_SIZE]
        = { { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
            { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
            { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
            { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
            { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
            { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
            { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
            { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
            { 0, 0, 0, 0, 8, 0, 0, 7, 9 } };

//find the next empty cell
bool empty(int board[BOARD_SIZE][BOARD_SIZE], int &row, int &col){
    for (int i = 0; i < BOARD_SIZE; i++){
        for (int j = 0; j < BOARD_SIZE; j++){
            if (board[i][j] == 0){
                row = i;
                col = j;
                return true;
            }

        }
    }
    return false;
}
/*
int solve_cell(int board){
    int row;
    int col;
    if (empty(board, row, col) == true){
        return true;
    }
    
    for (int num = 1; num <= 9; num++) {
        if (safe(board, row, col, num)) {
            board[row][col] = num;
            if (solve_cell(board)) {
                return true;
            }
            
            board[row][col] = 0;
        }
    }
}*/

bool safe(const int board[9][9], int row, int col, int num){

    //row
    for (int i = 0; i < BOARD_SIZE; i++){
        if (board[row][i] == num) {
            return false;
        }
    }
    //col
    for (int i = 0; i < BOARD_SIZE; i++){
        if (board[i][col] == num) {
            return false;
        }
    }
    //grid
    int m_r = row - row % GRID;
    int m_c = col - col % GRID;
    for(int i = 0; i < GRID; i++){
        for (int j = 0; j < GRID; j++){
            if(board[m_r + i][m_c + j] == num){
                return false;
            }
        }
    }

    //Number can be safely placed
    return true;

}

bool solveSudokuBacktracking(int board[BOARD_SIZE][BOARD_SIZE]){
    int row, col;
    if (!empty(board, row, col)) {
        return true;
    }
    for (int num = 1; num <= 9; num++){
        if (safe(board, row, col, num)){
            board[row][col] = num;
            if (solveSudokuBacktracking(board)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}


void print_board(int sudoku[BOARD_SIZE][BOARD_SIZE]){
    cout << endl << "-----------------" << endl;
    for(int row = 0; row < BOARD_SIZE; row++){
        for(int cell = 0; cell < BOARD_SIZE; cell++){
            cout << sudoku[row][cell] << " ";
        }
        cout << endl;
    }
    cout << "-----------------" << endl;
}

int main(){
    //display starting board
    std::cout << std::endl << "The starting board is: "; 
    print_board(board);

    //solve the board
    if (solveSudokuBacktracking(board)) {
        cout << "Solved Board: ";
        print_board(board);
    }else{
        std::cout << "No solution exists" << std::endl;
    }
    

    return 0;
}
