class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int totalElements = m * n;
        
        k = k % totalElements; 
        
        for (int shift = 0; shift < k; shift++) {
            vector<vector<int>> current = grid;
            
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j + 1 < n) {
                        swap(current[i][j], grid[i][j + 1]);
                    } 
                    else if (i + 1 < m && j == n - 1) {
                        swap(current[i][j], grid[i + 1][0]);
                    } 
                    else if (i == m - 1 && j == n - 1) {
                        swap(current[i][j], grid[0][0]);
                    }
                    
                }
            }
        }
        return grid;
    }
};
