class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int n, int i, vector<int>& dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i]; // Return already calculated result

        // 1-day pass
        int cost_1 = costs[0] + solve(days, costs, n, i + 1, dp);

        // 7-day pass
        int j = i;
        int max_day_7 = days[i] + 7;
        while (j < n && days[j] < max_day_7) {
            j++;
        }
        int cost_7 = costs[1] + solve(days, costs, n, j, dp);

        // 30-day pass
        j = i; // Reset pointer
        int max_day_30 = days[i] + 30;
        while (j < n && days[j] < max_day_30) {
            j++;
        }
        int cost_30 = costs[2] + solve(days, costs, n, j, dp);

        // Store and return the minimum
        return dp[i] = min({cost_1, cost_7, cost_30});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1); // DP array initialized to -1
        return solve(days, costs, n, 0, dp);
    }
};
