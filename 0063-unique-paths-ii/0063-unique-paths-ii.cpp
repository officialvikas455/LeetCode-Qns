class Solution{
    public:

int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (m == 0 && n==0) return 0; 
  
    std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));

    if (obstacleGrid[0][0] == 0) {
        dp[0][0] = 1;
    } else {
        return 0; 
    }

    // Fill the first column
    for (int i = 1; i < m; ++i) {
        if (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) {
            dp[i][0] = 1;
        }
    }

    // Fill the first row
    for (int j = 1; j < n; ++j) {
        if (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) {
            dp[0][j] = 1;
        }
    }

    // Fill the rest of the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (obstacleGrid[i][j] == 0) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}
};
