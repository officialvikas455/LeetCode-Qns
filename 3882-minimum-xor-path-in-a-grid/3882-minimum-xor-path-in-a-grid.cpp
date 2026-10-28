
class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    int dfs(int i, int j, int vk, vector<vector<int>>& grid) {
        if (i >= m || j >= n)
            return INT_MAX;

        vk ^= grid[i][j];

        if (i == m - 1 && j == n - 1)
            return vk;

        if (dp[i][j][vk] != -1)
            return dp[i][j][vk];

        int right = dfs(i, j + 1, vk, grid);
        int down = dfs(i + 1, j, vk, grid);

        return dp[i][j][vk] = min(right, down);
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(1024, -1)));

        return dfs(0, 0, 0, grid);
    }
};
