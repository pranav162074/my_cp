class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        mp[0] = 1;
        int prefixsum=0;
        int ans = 0;
        for (int i=0; i<nums.size(); i++) {
            prefixsum += nums[i];
            int need = prefixsum-k;
            ans += mp[need];
            mp[prefixsum]++;
        }
        return ans;
    }
};
