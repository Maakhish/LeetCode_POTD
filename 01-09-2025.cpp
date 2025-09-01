class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double, int>, vector<pair<double, int>>> pq;
        for(int ind = 0; ind < n; ind++){
            int currPass = classes[ind][0];
            int currTotal = classes[ind][1];
            int nextPass = currPass + 1;
            int nextTotal = currTotal + 1;
            double passRatio1 = static_cast<double>((currPass*1.0) / currTotal);
            double passRatio2 = static_cast<double>((nextPass*1.0) / nextTotal);
            pq.push({passRatio2 - passRatio1, ind});
        }
        for(int i = 0; i < extraStudents; i++){
            auto choose = pq.top();
            pq.pop();
            int ind = choose.second;
            classes[ind][0] += 1;
            classes[ind][1] += 1;

            int currPass = classes[ind][0];
            int currTotal = classes[ind][1];
            int nextPass = currPass + 1;
            int nextTotal = currTotal + 1;
            double passRatio1 = static_cast<double>((currPass*1.0) / currTotal);
            double passRatio2 = static_cast<double>((nextPass*1.0) / nextTotal);
            pq.push({passRatio2 - passRatio1, ind});
        }
        double maxTotalPassRatio = 0;
        for(auto ele: classes){
            double passRatio = static_cast<double>((ele[0] * 1.0) / ele[1]);
            maxTotalPassRatio += passRatio;
        }
        return maxTotalPassRatio / n;
    }
};
