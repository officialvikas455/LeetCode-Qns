class Solution {
public:
    long long solve(int index, int buy, int transaction, int n,
                     vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        // agar transactions hi khatam ho gaye to aage kuch fayda nahi
        if (transaction == 0)
            return 0;

        // array khatam ho gaya
        if (index == n) {
            // agar short position khuli reh gayi (buy == 1) to invalid -> INT_MIN
            // warna profit 0
            return buy == 1 ? INT_MIN : 0;
        }

        if (dp[index][buy][transaction] != -1)
            return dp[index][buy][transaction];

        if (buy == 2) {
            // NEUTRAL: skip karo, ya long lo, ya short karo
            long long skip = solve(index + 1, 2, transaction, n, prices, dp);
            long long goLong = -prices[index] + solve(index + 1, 0, transaction, n, prices, dp);
            long long goShort = prices[index] + solve(index + 1, 1, transaction, n, prices, dp);

            return dp[index][buy][transaction] = max(skip, max(goLong, goShort));
        } else if (buy == 1) {
            // SHORT position khuli hai: cover karo (buy back) ya hold karo
            long long cover = -prices[index] + solve(index + 1, 2, transaction - 1, n, prices, dp);
            long long hold  = solve(index + 1, 1, transaction, n, prices, dp);

            return dp[index][buy][transaction] = max(cover, hold);
        } else {
            // LONG position khuli hai: bech do ya hold karo
            long long sell = prices[index] + solve(index + 1, 2, transaction - 1, n, prices, dp);
            long long hold = solve(index + 1, 0, transaction, n, prices, dp);

            return dp[index][buy][transaction] = max(sell, hold);
        }
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n + 1, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));

        // 0th index se start, "2" = neutral state se shuru karte hain
        return solve(0, 2, k, n, prices, dp);
    }
};