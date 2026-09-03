class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;

        // Already visited or water
        if (vis[i][j] || grid[i][j] == '0')
            return;

        // Mark current cell visited
        vis[i][j] = true;

        // UP
        dfs(i - 1, j, vis, grid);

        // DOWN
        dfs(i + 1, j, vis, grid);

        // LEFT
        dfs(i, j - 1, vis, grid);

        // RIGHT
        dfs(i, j + 1, vis, grid);
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // New island found
                if (!vis[i][j] && grid[i][j] == '1') {

                    ans++;

                    dfs(i, j, vis, grid);
                }
            }
        }

        return ans;
    }
};