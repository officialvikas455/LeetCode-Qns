class Solution {
public:
    int solve(int idx, int buy, int trans , int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
        if(trans == 0 || idx == n) return 0;

        if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];

        if(buy){
            return dp[idx][buy][trans] =  max(-prices[idx] + solve(idx+1,0,trans,n,prices,dp), solve(idx+1,1,trans,n,prices,dp));
        } else{
             return dp[idx][buy][trans] = max(prices[idx] + solve(idx+1,1,trans-1,n,prices,dp), solve(idx+1,0,trans,n,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,1,2,n,prices,dp);
    }
};