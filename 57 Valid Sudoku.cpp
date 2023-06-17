bool thiklgrhahai(int (*board)[9], int value, int row, int col){
    for(int i=0; i<9; i++){
        if(board[row][i] == value)
            return false;

        if(board[i][col] == value)
            return false;

        if(board [3*(row/3) + i/3][3*(col/3) + i%3] == value)
            return false;
    }
    return true;
}


bool dfs(int (*board)[9]){
    int n = 9;

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            if(board[row][col] == 0){
                
                for(int ch=1; ch<=9; ch++){
                    if(thiklgrhahai(board, ch, row, col)){
                        board[row][col] = ch;
                        bool damn = dfs(board);
                        if(damn)
                            return true;
                        else 
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true                                                                     ;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    return dfs(matrix);
}
