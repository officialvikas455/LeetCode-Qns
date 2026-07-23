class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int total = 0;
        for(int x : nums) total += x;

        if((target + total) % 2 != 0 || abs(target) > total) return 0;

        int sum = (target + total) / 2;

        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));

        dp[0][0] = 1; 

        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                if(nums[i-1] <= j){
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};