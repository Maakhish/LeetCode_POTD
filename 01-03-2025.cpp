vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n - 1; i++){
        if(nums[i] == nums[i + 1]){
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
        if(nums[i] != 0){
            nums[j] = nums[i];
            j++;
        }
    }
    if(nums[n - 1] != 0){
        nums[j++] = nums[n - 1];
    }
    while (j < n){
        nums[j++] = 0;
    }
    return nums;
}

// here whenever nums[i] = nums[i + 1] we make nums[i] = nums[i] * 2 and nums[i + 1] = 0
// like this we do n - 1 operations i.e i starts from 0 and ends at n - 1
// at last shift all the zeros to the end of the array i.e [1, 0, 2, 0, 1, 0] -> [1, 2, 1, 0, 0, 0]
// for this we need to do O(n) for operations
// at the same time we can process the nums array as well 
// we maintain an index j to push non zero elements into nums
// since i reaches only until n - 2
// we need to process n - 1th element
// we check if its non zero if yes we add
// then from j to n we add zeroes and return nums array