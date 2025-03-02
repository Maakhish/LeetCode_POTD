vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums1.size(); i++){
        mp[nums1[i][0]] = i;
    }
    for(auto& ele: nums2){
        int id = ele[0];
        if(mp.find(id) != mp.end()){
            // common in both
            nums1[mp[id]][1] += ele[1];
        }
        else{
            nums1.push_back(ele);
        }
    }
    sort(nums1.begin(), nums1.end());
    return nums1;
}

// we need to track id's present in nums1 so we use a map
// at that position where id is there if that id is also in nums2 we sum up the values
// like this we will do and return nums1 itself which consumes less space than creating a answer array