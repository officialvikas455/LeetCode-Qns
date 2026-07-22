class Solution {
public:
    long long solve(int index, int buy, int transaction, int n,
                    vector<int>& prices ,vector<vector<vector<long long>>>& dp) {
        if (transaction == 0)
            return 0;
        if (index == n) {
            return buy == 1 ? INT_MIN : 0;
        }
        if (dp[index][buy][transaction] != -1)
            return dp[index][buy][transaction];
        // max(ya mai purchase nhi karunga  , yaa karunga yaa mai ,  short sell karunga)
        if (buy == 2) {
            return dp[index][buy][transaction] =
                       max(solve(index + 1, 2, transaction, n, prices,dp),
                           max(-prices[index] +
                                   solve(index + 1, 0, transaction, n, prices,dp),
                               prices[index] + solve(index + 1, 1, transaction,
                                                     n, prices,dp)));
        } else if (buy == 1) {
            // short selling karunga yaa nhi
            return dp[index][buy][transaction] =
                       max(-prices[index] +
                               solve(index + 1, 2, transaction - 1, n, prices,dp),
                           solve(index + 1, 1, transaction, n, prices,dp));
        } else {
            // normal selling
            // sell karenge             yaa sell nhi karenge
            return dp[index][buy][transaction] =
                       max(prices[index] +
                               solve(index + 1, 2, transaction - 1, n, prices,dp),
                           solve(index + 1, 0, transaction, n, prices,dp));
        }
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        return solve(0, 2, k, n, prices, dp);
    }
};