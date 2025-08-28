class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            return grid;
        }
        int k1 = n - 1; // no.of diagnols possible on the lower triangle side
        int k2 = n - 2; // no.of diagnols possible on the upper triangle side
        int i = 0;
        while(k1--){
            vector<int> d;
            for(int j = 0; i + j < n; j++){
                d.push_back(grid[i + j][j]);
            }
            sort(d.rbegin(), d.rend()); // dec order
            for(int j = 0; i + j < n; j++){
                grid[i + j][j] = d[j];
            }
            i++;
        }
        int j = 1;
        while(k2--){
            vector<int> d;
            for(int i = 0; i + j < n; i++){
                d.push_back(grid[i][i + j]);
            }
            sort(d.begin(), d.end()); // inc order
            for(int i = 0; i + j < n; i++){
                grid[i][i + j] = d[i];
            }
            j++;
        }
        return grid;
    }
};
