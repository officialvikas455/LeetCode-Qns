class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prevCount(k, 0);

        for (int i = 0; i < n; i++) {

            // All subarrays ending at index i
            vector<long long> currCount(k, 0);

            // Subarray containing only nums[i]
            int currElementCount = nums[i] % k;
            currCount[currElementCount]++;

            // Extend all previous subarrays with nums[i]
            for (int oldRem = 0; oldRem < k; oldRem++) {

                int newRem = ((long long)oldRem * nums[i]) % k;

                currCount[newRem] += prevCount[oldRem];
            }

            prevCount = move(currCount);

            // Add subarrays ending at i to final answer
            for (int x = 0; x < k; x++) {
                result[x] += prevCount[x];
            }
        }

        return result;
    }
};