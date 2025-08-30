class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), box(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char num = board[i][j];
                    int bi = (i / 3) * 3 + (j / 3);
                    if(row[i].count(num) || col[j].count(num) || box[bi].count(num))
                        return false;
                    row[i].insert(num);
                    col[j].insert(num);
                    box[bi].insert(num);
                }
            }
        }
        return true;
    }
};
