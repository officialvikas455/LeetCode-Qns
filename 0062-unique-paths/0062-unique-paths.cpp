class Solution {
public: 
// Memoization
//  int solve(int r, int c, int m, int n,vector<vector<int>> &dp){
//     if(r==m-1 && c == n-1) return 1;
//     if(r>=m || c>=n) return 0; 

//     if(dp[r][c] != -1)  return dp[r][c]; 

//     int right = solve(r, c+1, m, n,dp);
//     int down = solve(r+1,c, m, n,dp);
//     return dp[r][c] = right + down; 
//  }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else {
                    int up = (i > 0) ? dp[i - 1][j] : 0;
                    int left = (j > 0) ? dp[i][j - 1] : 0;
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
