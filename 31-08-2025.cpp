class Solution {
public:
    bool possible(vector<vector<char>>& board, int row, int col, char num){
        for(int i=0;i<9;i++){
            if(board[row][i] == num)
                return false;
            if(board[i][col] == num)
                return false;
            if(board[(3*(row/3) + (i/3))][(3*(col/3) + (i%3))] == num)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        // check for empty spaces
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    // if this is empty cell then start placing

                    for(char num = '1';num<='9';num++){
                        if(possible(board, i, j, num)){
                            // if possible to place it then place it and 
                            board[i][j] = num;
                            // make a recursive call to try solving
                            // this new sudoku we got 
                            // if we are able to solve return true
                            if(solve(board) == true)
                                return true;
                            else{
                                // if not possible to solve new sudoku
                                // remove this number and solve again 
                                board[i][j] = '.';
                            }
                        }
                    }
                    // if we cannot place none of the numbers there return false 
                    return false;
                }
            }
        }
        // now if we have completed checking whole board
        // that means we seen all empty spaces 
        // so we can solve this sudoku 
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
