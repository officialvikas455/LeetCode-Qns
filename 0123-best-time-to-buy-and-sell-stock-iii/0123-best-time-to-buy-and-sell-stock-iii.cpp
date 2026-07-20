class Solution {
public:
     
    // int solve(int idx, int buy, int trans , int n,vector<int>& prices,vector<vector<vector<int>>> &dp){
    //     if(trans == 0 || idx == n) return 0;

    //     if(dp[idx][buy][trans] != -1) return dp[idx][buy][trans];

    //     if(buy){
    //         return dp[idx][buy][trans] =  max(-prices[idx] + solve(idx+1,0,trans,n,prices,dp), solve(idx+1,1,trans,n,prices,dp));
    //     } else{
    //          return dp[idx][buy][trans] = max(prices[idx] + solve(idx+1,1,trans-1,n,prices,dp), solve(idx+1,0,trans,n,prices,dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
    int n = prices.size();

    vector<vector<vector<int>>> dp(
        n + 1,
        vector<vector<int>>(2, vector<int>(3, 0))
    );

        vector<vector<int>> prev(2, vector<int>(3, 0));
        




    for (int i = n - 1; i >= 0; i--) {
        vector<vector<int>> curr(2, vector<int>(3, 0));
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= 2; cap++) {

                if (buy) {
                   curr[buy][cap] = max(
                        -prices[i] + prev[0][cap],   // Buy
                        prev[1][cap]                  // Skip
                    );
                } else {
                   curr[buy][cap] = max(
                        prices[i] + prev[1][cap - 1], // Sell
                        prev[0][cap]                  // Skip
                    );
                }
            }
        }
        prev = curr;
    }

    return prev[1][2];
}
};