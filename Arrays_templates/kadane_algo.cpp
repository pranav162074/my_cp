//kadane's algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int maxisum=INT_MIN;
        for (int num : nums) {
            sum += num;
            maxisum = max(maxisum, sum);
            if (sum<0) sum=0;
        }
        return maxisum;
    }
};

/*to even print the subarray consisting that subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int maxisum=INT_MIN;
        int start=0, anstart=0, ansend=0;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            if (sum>maxisum) {
                maxisum = sum;
                anstart=start;
                ansend=i;
            }
            if (sum<0) {
                sum=0;
                start=i+1;
            }
        }
        for (int i=anstart; i<=ansend; i++) {
            cout << nums[i] << " ";
        }
        return maxisum;
    }
};
*/
