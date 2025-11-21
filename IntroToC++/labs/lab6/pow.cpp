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
}