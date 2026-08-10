// class Solution {
// public:
//     bool winnerSquareGame(int n) {
//         vector<bool> dp(n + 1, false);
//         for (int i = 1; i <= n; ++i) {
//             for (int j = 1; j * j <= i; ++j) {
//                 if (!dp[i - j * j]) {
//                     dp[i] = true;
//                     break; 
//                 }
//             }
//         }
        
//         return dp[n];
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;

    bool solve(int n) {
        if (n == 0) return false;

        if (dp[n] != -1) return dp[n];

        for (int j = 1; j * j <= n; j++) {
            // If opponent loses after taking j*j stones
            if (!solve(n - j * j)) {
                return dp[n] = true;
            }
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        dp.assign(n + 1, -1);
        return solve(n);
    }
};
