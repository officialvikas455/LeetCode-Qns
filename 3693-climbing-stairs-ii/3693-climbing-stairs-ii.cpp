class Solution {
public:
    int dp[100001];

    int solve(int i, int n, vector<int>& costs) {
        if (i >= n) return 0;
        
        if (dp[i] != -1) return dp[i];

        int minCost = 1e9; 

        // Try jumping 1 step
        int j = i + 1;
        if (j <= n) {
            minCost = min(minCost, (costs[j - 1] + (j - i) * (j - i)) + solve(j, n, costs));
        }

        // Try jumping 2 steps
        j = i + 2;
        if (j <= n) {
            minCost = min(minCost, (costs[j - 1] + (j - i) * (j - i)) + solve(j, n, costs));
        }

        // Try jumping 3 steps
        j = i + 3;
        if (j <= n) {
            minCost = min(minCost, (costs[j - 1] + (j - i) * (j - i)) + solve(j, n, costs));
        }

        return dp[i] = minCost;
    }

    int climbStairs(int n, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, costs);
    }
};
