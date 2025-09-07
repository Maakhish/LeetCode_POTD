class Solution {
public:
    vector<int> sumZero(int n) {
        bool isOdd = false;
        if(n == 1)
            return {0};
        if(n % 2){
            isOdd = true;
            n--;
        }
        int i = 1;
        int cnt = 0;
        vector<int> ans;
        while(cnt < n){
            ans.emplace_back(i);
            ans.emplace_back(-1 * i);
            i++;
            cnt += 2;
        }
        if(isOdd)
            ans.emplace_back(0);
        return ans;
    }
};
