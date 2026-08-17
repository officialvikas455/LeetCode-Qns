class Solution {
public:
    int dp[501][501];

    int solve(vector<int>& v, int l, int r, vector<int>& prefix) {
        if (l == r)
            return 0;

        // Already calculated
        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        // Try every possible split
        for (int i = l; i < r; i++) {

            int leftSum = prefix[i + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[i + 1];

            if (leftSum < rightSum) {
                ans = max(ans,
                          leftSum + solve(v, l, i, prefix));
            }
            else if (rightSum < leftSum) {
                ans = max(ans,
                          rightSum + solve(v, i + 1, r, prefix));
            }
            else {
                ans = max(ans,
                          leftSum + max(
                              solve(v, l, i, prefix),
                              solve(v, i + 1, r, prefix)
                          ));
            }
        }

        return dp[l][r] = ans;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();

        memset(dp, -1, sizeof(dp));

        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }

        return solve(stoneValue, 0, n - 1, prefix);
    }
};