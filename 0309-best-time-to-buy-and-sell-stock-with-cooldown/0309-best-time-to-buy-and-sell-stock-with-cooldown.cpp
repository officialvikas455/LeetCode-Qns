// class Solution {
// public:


//     int solve(int ind, int buy, int n, vector<int>& prices,vector<vector<int>> &dp) {
//         if (ind >= n) return 0;
//         if (dp[ind][buy] != -1) return dp[ind][buy];

//         if (buy) {
//             // We can either buy or skip buying
//             return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, n, prices,dp), 
//                          solve(ind + 1, 1, n, prices,dp));
//         } else {
//             //  If we sell, we jump to ind + 2 to enforce a 1-day cooldown
//            return  dp[ind][buy]  = max(prices[ind]  + solve(ind + 2, 1, n, prices,dp), 
//                          solve(ind + 1, 0, n, prices,dp));
//         }
//     }

//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2,-1));
//         return solve(0,1,n,prices,dp);
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        // DP table size (n+2) x 2 initialized to 0. 
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        vector<int> prev1(2, 0), prev2 = prev1;

        for (int ind = n - 1; ind >= 0; ind--) {
            vector<int> curr(2, 0);
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) {
                    // Option 1: Buy today -> next day we must sell (buy=0)
                    // Option 2: Skip today -> next day we can still buy (buy=1)
                   curr[buy] = max(-prices[ind] + prev1[0], 
                                       prev1[1]);
                } else {
                    // Option 1: Sell today -> skip next day due to cooldown (jump to ind+2, buy=1)
                    // Option 2: Skip today -> next day we must still sell (buy=0)
                   curr[buy] = max(prices[ind] + prev2[1], 
                                       prev1[0]);
                }
            }
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1[1];
    }
};


