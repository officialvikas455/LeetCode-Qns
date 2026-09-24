class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (n == k)
            return sum;

        int maxScore = 0;
        for (int i = 0; i < k; i++) {
            maxScore += nums[i];
        }

        int right = n - 1;
        int currentScore = maxScore;

        for (int i = k - 1; i >= 0; i--) {
            currentScore -= nums[i];
            currentScore += nums[right];

            maxScore = max(maxScore, currentScore);

            right--;
        }

        return maxScore;
    }
};