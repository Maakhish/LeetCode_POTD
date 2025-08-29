class Solution {
public:
    long long flowerGame(int n, int m) {
        long long no = (n + 1) / 2;
        long long ne = (n / 2);
        long long mo = (m + 1) / 2;
        long long me = (m / 2);
        long long p1 = static_cast<long long>(no * me );
        long long p2 = static_cast<long long>( ne * mo );
        return static_cast<long long>(p1 + p2);
    }
};
