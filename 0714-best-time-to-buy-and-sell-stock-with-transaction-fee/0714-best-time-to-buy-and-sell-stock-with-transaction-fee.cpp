#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

class Solution {
    int dp[50005][2];

    int solve(int ind, int buy, int n, int fee, vector<int>& prices) {
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        int profit = 0;
        if (buy) {
            // We can either buy or skip buying
            profit = max(-prices[ind] + solve(ind + 1, 0, n, fee, prices), 
                         solve(ind + 1, 1, n, fee, prices));
        } else {
            // We can either sell (and pay the fee) or skip selling
            profit = max(prices[ind] - fee + solve(ind + 1, 1, n, fee, prices), 
                         solve(ind + 1, 0, n, fee, prices));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memset(dp, -1, sizeof(dp)); 
        return solve(0, 1, n, fee, prices);
    }
};
