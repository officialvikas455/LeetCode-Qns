class Solution {
public:
    int n;
    vector<int> dp;

    int solve(vector<int>& prefix, int i) {
        if (i == n - 1)
            return prefix[i];

        if (dp[i] != INT_MIN)
            return dp[i];

        int take = prefix[i] - solve(prefix, i + 1);

        return dp[i] = max(take, solve(prefix, i + 1));
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();

        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        dp.assign(n, INT_MIN);

        return solve(stones, 1);
    }
};