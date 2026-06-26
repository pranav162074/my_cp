int longestSubarrayWithSumK(vector<int>& arr, int k) {
    unordered_map<long long, int> firstIndex;

    long long prefixSum = 0;
    int maxLen = 0;

    for (int i = 0; i < (int)arr.size(); i++) {
        prefixSum += arr[i];

        // if whole prefix matches k
        if (prefixSum == k) {
            maxLen = max(maxLen, i + 1);
        }

        // important: store only FIRST occurrence
        /*
          Because, (NOTE: For the longest subarray, you must keep the first occurrence of each prefix sum, 
          because the earliest index gives the maximum length.) 
        */
        if (firstIndex.find(prefixSum) == firstIndex.end()) {
            firstIndex[prefixSum] = i;
        }

        // check if (prefixSum - k) exists
        if (firstIndex.find(prefixSum - k) != firstIndex.end()) {
            int j = firstIndex[prefixSum - k];
            maxLen = max(maxLen, i - j);
        }
    }

    return maxLen;
}

int main() {
    vector<int> arr = {10, 5, 2, 7, 1, -10, 3};
    int k = 15;

    cout << longestSubarrayWithSumK(arr, k) << endl;
}
