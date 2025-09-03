class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();

        sort(points.begin(), points.end(), [&](const vector<int>& point1, const vector<int>& point2) {
            if(point1[0] == point2[0])
                return point1[1] > point2[1];
            return point1[0] < point2[0];
        });

        int ans = 0;
        
        for(int i = 0; i < n - 1; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            int maxYMid = INT_MIN;

            for(int j = i + 1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                if(y2 > y1){
                    continue;
                }

                if(y2 > maxYMid){
                    ans++;
                    maxYMid = y2;
                }
            }
        }
        return ans;
    }
};
