
using namespace std;

class Solution {

    int solve(int ind, int buy, int n, int fee, vector<int>& prices,vector<vector<int>> &dp) {
        if (ind == n) return 0;
        if (dp[ind][buy] != -1) return dp[ind][buy];

        if (buy) {
            // We can either buy or skip buying
            return dp[ind][buy] = max(-prices[ind] + solve(ind + 1, 0, n, fee, prices,dp), 
                         solve(ind + 1, 1, n, fee, prices,dp));
        } else {
            // We can either sell (and pay the fee) or skip selling
           return  dp[ind][buy]  = max(prices[ind] - fee + solve(ind + 1, 1, n, fee, prices,dp), 
                         solve(ind + 1, 0, n, fee, prices,dp));
        }
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
    //   vector<vector<int>> dp(n+1, vector<int>(2,-1));
       vector<vector<int>> dp(n+1, vector<int>(2,0));


       for(int ind = n-1; ind >= 0; ind--){
        for(int buy=0; buy<=1; buy++){

            if(buy){
                 dp[ind][buy] = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
            }else{
                 dp[ind][buy] = max(prices[ind]-fee+dp[ind+1][1],dp[ind+1][0]);
            }
         }
       }
        // return solve(0, 1, n, fee, prices,dp);
        return dp[0][1];
    }
};
