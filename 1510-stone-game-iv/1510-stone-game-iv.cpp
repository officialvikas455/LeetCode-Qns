class Solution {
public:
    bool winnerSquareGame(int n) {
        // dp[i] stores whether the current player can win with i stones remaining
        vector<bool> dp(n + 1, false);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                // If the opponent loses after we take j*j stones, we win
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break; 
                }
            }
        }
        
        return dp[n];
    }
};
