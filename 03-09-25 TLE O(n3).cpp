class Solution {
private: 
    bool luhs(vector<int>& a, vector<int>& b){
        return (a[0] <= b[0]) && (a[1] >= b[1]);
    }
    bool noOtherInside(vector<int>& a, vector<int>& b, vector<vector<int>>& points){
        for(auto p: points){
            int x = p[0];
            int y = p[1];
            if((x == a[0] && y == a[1]) || (x == b[0] && y == b[1]))
                continue;
            if((a[0] <= x && x <= b[0]) && (a[1] >= y && y >= b[1]))
                return false; 
        }
        return true;
    }
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                auto p1 = points[i];
                auto p2 = points[j];
                if(luhs(p1, p2)){
                    if(noOtherInside(p1, p2, points)){
                        ans++;
                    }
                }
                if(luhs(p2, p1)){
                    if(noOtherInside(p2, p1, points))
                        ans++;
                }
            }
        }
        return ans;
    }
};

// This is same yesterday's code but gives TLE since now n <= 1000 is given and this code tc is O(n3) so it exceeds time limit 
