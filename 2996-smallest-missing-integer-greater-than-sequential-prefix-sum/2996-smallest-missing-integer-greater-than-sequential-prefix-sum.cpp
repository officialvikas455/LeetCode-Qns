class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // 1. Calculate the sum of the longest sequential prefix
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                sum += nums[i];
            } else {
                break; // Stop as soon as the sequence breaks
            }
        }
        
        // 2. Insert all numbers into a hash set for quick lookup
        unordered_set<int> num_set(nums.begin(), nums.end());
        
        // 3. Find the smallest missing integer >= sequential prefix sum
        while (num_set.count(sum)) {
            sum++;
        }
        
        return sum;
    }
};
