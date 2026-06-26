class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotindx = -1;
        for (int i=n-2; i>=0; i--) {
            if (nums[i]<nums[i+1]) {
                pivotindx = i;
                break;
            }
        }
        if (pivotindx==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int i=n-1; i>=pivotindx+1; i--) {
            if (nums[i]>nums[pivotindx]) {
                swap(nums[i], nums[pivotindx]);
                break;
            }
        }
        reverse(nums.begin()+pivotindx+1, nums.end());
    }
};
