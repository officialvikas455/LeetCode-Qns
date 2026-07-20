class Solution {
public:

   int rec(int ind, vector<int> &prices, int buy,int n, vector<vector<int>> &dp){
    if(ind==n){
        return 0;
    } 
    if(dp[ind][buy] != -1){
        return dp[ind][buy];
    }
        int profit=0;

        if(buy){
            int buy = -prices[ind]+ rec(ind+1, prices, 1, n, dp);
            int notBuy = rec(ind+1, prices, 0, n, dp);
             profit = max(buy, notBuy);
        }else{ 
            int sell = prices[ind] + rec(ind+1,prices, 0,n ,dp);
            int notSell = rec(ind+1,prices,1, n, dp);

            profit = max(sell, notSell);

        }
        dp[ind][buy] = profit;
        return profit;
 }
  
    int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 

    dp[n][0] = dp[n][1] = 0; 

    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if (buy) {
                // Buy today or skip
                int take = -prices[ind] + dp[ind + 1][0];
                int notTake = 0 + dp[ind + 1][1];
                profit = max(take, notTake);
            } else {
                // Choice: Sell today or skip
                int take = prices[ind] + dp[ind + 1][1];
                int notTake = 0 + dp[ind + 1][0];
                profit = max(take, notTake);
            }
            dp[ind][buy] = (int)profit;
        }
    }
    return dp[0][1];
}
};