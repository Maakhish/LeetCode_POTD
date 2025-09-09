class Solution {
private: 
    int noPeopleValid(unordered_map<int, pair<int, int>>& mp, int delay, int day){
        int cnt = 0;
        for(auto ele: mp){
            int d = day - ele.second.second;
            if(d >= delay)
                cnt++;
        }
        return cnt;
    }
    void reduceProc(unordered_map<int, pair<int, int>>& mp){
        vector<int> toErase;
        for(auto& ele: mp){
            ele.second.first--;
            if(ele.second.first == 0){
                toErase.push_back(ele.first);
            }
        }
        for(int id: toErase)
            mp.erase(id);
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        unordered_map<int, pair<int, int>> mp;
        int tempIdx = 1;

        mp[0] = {forget, 1};
        for(int day = 2; day <= n; day++){
            reduceProc(mp);
            int p = noPeopleValid(mp, delay, day);
            while(p){
                mp[tempIdx++] = {forget, day};
                p--;
            }
        }
        return mp.size();
    }
};
