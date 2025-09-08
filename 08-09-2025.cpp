class Solution {
private: 
    bool isNoZero(int num){
        while(num > 0){
            int d = num % 10;
            if(d == 0)
                return false;
            num /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            if(isNoZero(i) && isNoZero(n - i)){
                return {i, n - i};
            }
        }
        return {n - 1, 1};
    }
};
