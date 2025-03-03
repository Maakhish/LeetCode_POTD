vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    vector<int> ans(n);
    for(int i = 0, j = n - 1; i < n && j >= 0; i++,j--){
        if(nums[i] < pivot){
            ans[start] = nums[i];
            start++;
        }
        if(nums[j] > pivot){
            ans[end] = nums[j];
            end--;
        }
    }
    while(start <= end){
        ans[start] = pivot;
        start++;
    }
    return ans;
}

// all numbers less than pivot should be before it
// all numbers greater than pivot should be after it
// in middle pivot equal elements
// so we maintain 2 indices start and end to place elements as per conditions in ans array
// but the relative order must be maintained
// suppose 14, 12, 8, 10 and pivot is 10 then output is 8, 10, 14, 12 i.e 14 occured before 12 so rel position must be sae
// to maintain this for larger elements the ones that are most right must be placed last
// similarly for smaller elements the ones that are most left must be placed first
// so maintain pointers i and j
// i for smaller 
// j for larger and j starts at last