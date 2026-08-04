// class Solution {
// public:
//     const int INF = 1e9;

//     int solve(vector<int>& stones, int i, vector<int>& dp) {
//         int n = stones.size();

//         if (i >= n) return 0;

//         if (dp[i] != -INF) return dp[i];

//         int first = stones[i] - solve(stones, i + 1, dp);

//         int second = -INF;
//         if (i + 1 < n) {
//             second = stones[i] + stones[i + 1]
//                    - solve(stones, i + 2, dp);
//         }

//         int third = -INF;
//         if (i + 1 < n && i + 2 < n) {
//             third = stones[i] + stones[i + 1] + stones[i + 2]
//                   - solve(stones, i + 3, dp);
//         }

//         return dp[i] = max({first, second, third});
//     }

//     string stoneGameIII(vector<int>& stoneValue) {
//         int n = stoneValue.size();
//         vector<int> dp(n, -INF);

//         int score = solve(stoneValue, 0, dp);

//         if (score > 0) return "Alice";
//         else if (score < 0) return "Bob";
//         return "Tie";
//     }
// };


class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        const int NEG_INF = -1e9;

        vector<int> dp(n + 1, 0);   // dp[n] = 0 (base case)
        for (int i = n - 1; i >= 0; i--) {
            int best = NEG_INF;
            int take = 0;
            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                best = max(best, take - dp[i + k + 1]);
            }
            dp[i] = best;
        }

        int score = dp[0];
        if (score > 0) return "Alice";
        else if (score < 0) return "Bob";
        return "Tie";
    }
};