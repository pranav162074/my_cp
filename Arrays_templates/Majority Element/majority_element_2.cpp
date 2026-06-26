//only two elements are possible
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int candidate1 = INT_MIN, candidate2 = INT_MIN;
        for (int i=0; i<n; i++) {
            if (cnt1 == 0 && nums[i] != candidate2) {
                cnt1=1;
                candidate1 = nums[i];
            } else if (cnt2 == 0 && nums[i] != candidate1) {
                cnt2=1;
                candidate2= nums[i];
            } else if (nums[i] == candidate1) {
                cnt1++;
            } else if (nums[i] == candidate2) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;
        vector<int> ls;
        for (int i=0; i<n; i++) {
            if (candidate1 == nums[i]) cnt1++;
            if (candidate2 == nums[i]) cnt2++;
        }
        int mincondition = (int)(n/3);
        if (cnt1 > mincondition) ls.push_back(candidate1);
        if (cnt2 > mincondition) ls.push_back(candidate2);
        return ls;
    }
};
