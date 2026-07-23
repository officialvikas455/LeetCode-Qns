class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;
    
        if ((target + total) % 2 != 0 || abs(target) > total) return 0;
        
        int sum = (target + total) / 2;
        vector<int> dp(sum + 1, 0);
        dp[0] = 1; 
        
        for (int x : nums) {
            for (int j = sum; j >= x; j--) {
                dp[j] += dp[j - x];
            }
        }
        
        return dp[sum];
    }
};
