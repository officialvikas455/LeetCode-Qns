class Solution {
public:
    int m, n;
    int t[105][105][205]; 

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        if (i >= m || j >= n) return false; 

        if (grid[i][j] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) return false;
        
        if (balance > (m - 1 - i + n - 1 - j)) return false; 

        if (i == m - 1 && j == n - 1) return balance == 0; 

        if (t[i][j][balance] != -1) return t[i][j][balance]; 

        bool right = solve(i, j + 1, balance, grid);
        bool down = solve(i + 1, j, balance, grid);

        return t[i][j][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        if ((m + n - 1) % 2 != 0) return false; 
        
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, grid);
    }
};
