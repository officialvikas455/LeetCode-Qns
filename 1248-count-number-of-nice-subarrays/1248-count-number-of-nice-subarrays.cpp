class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int oddCount = 0;
        int totalSubarrays = 0;
        int currentSubarrayCount = 0;

        while (right < n) {
            // If the current element is odd, increment our odd counter
            if (nums[right] % 2 != 0) {
                oddCount++;
                // Reset the valid subarray count for this window
                currentSubarrayCount = 0;
            }

            // When we have exactly k odd numbers, shrink the window from the left
            while (oddCount == k) {
                currentSubarrayCount++;
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            // Add the valid subarrays ending at 'right' to the total
            totalSubarrays += currentSubarrayCount;
            right++;
        }

        return totalSubarrays;
    }
};
