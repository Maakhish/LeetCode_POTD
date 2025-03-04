class Solution {
    public:
        bool checkPowersOfThree(int n) {
            int power = 0;
            while(pow(3, power) <= n){
                power++;
            }
            while(n){
                if(n >= pow(3, power))
                    n -= pow(3, power);
                // we can't use same power twice
                if(n >= pow(3, power))
                    return false;
                power--;
            }
            return true;
        }
    };

    
    // start with largest power 3
    // keep subtracting like that