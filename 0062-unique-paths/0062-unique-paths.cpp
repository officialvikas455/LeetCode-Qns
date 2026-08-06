

class Solution {
public:
    int f(int r, int c, int m, int n, vector<vector<int>> &dp) {
        // Base case: Reached the bottom-right corner
        if (r == m - 1 && c == n - 1) return 1;
        
        // Base case: Out of bounds
        if (r >= m || c >= n) return 0;

        if(dp[r][c] != -1) return dp[r][c];

        return dp[r][c] = f(r, c + 1, m, n, dp) + f(r + 1, c, m, n, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(0, 0, m, n, dp);
    }
}; 
