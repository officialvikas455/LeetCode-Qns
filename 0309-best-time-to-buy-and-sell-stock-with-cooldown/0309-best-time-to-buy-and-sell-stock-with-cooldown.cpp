class Solution {
public:


    int solve(int ind, int buy, int n, vector<int>& prices,vector<vector<int>> &dp) {
        if (ind >= n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            // We can either buy or skip buying
            return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, n, prices,dp), 
                         solve(ind + 1, 1, n, prices,dp));
        } else {
            //  If we sell, we jump to ind + 2 to enforce a 1-day cooldown
           return  dp[ind][buy]  = max(prices[ind]  + solve(ind + 2, 1, n, prices,dp), 
                         solve(ind + 1, 0, n, prices,dp));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
    }
};