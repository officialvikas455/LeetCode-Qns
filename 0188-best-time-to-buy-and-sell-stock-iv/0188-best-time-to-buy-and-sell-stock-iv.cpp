class Solution {
public:
    int maxProfit(int cap, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>> prev(2, vector<int>(cap + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            vector<vector<int>> curr(2, vector<int>(cap + 1, 0));

            for (int buy = 0; buy <= 1; buy++) {
                for (int k = 1; k <= cap; k++) {

                    if (buy) {
                        curr[buy][k] = max(
                            -prices[i] + prev[0][k],   // Buy
                            prev[1][k]                 // Skip
                        );
                    } else {
                        curr[buy][k] = max(
                            prices[i] + prev[1][k - 1], // Sell
                            prev[0][k]                  // Skip
                        );
                    }
                }
            }

            prev = curr;
        }

        return prev[1][cap];
    }
};