class Solution {
public:
    int t[201][201];
    
    int solve(int r, int c, vector<vector<int>>& matrix){
        if(t[r][c] != -1) return t[r][c]; 
        
       
        int ans = 1; 
        
        // UP
        if(r-1 >= 0 && matrix[r][c] > matrix[r-1][c]){
            ans = max(ans, solve(r-1, c, matrix) + 1);
        }
        // DOWN
        if(r+1 < matrix.size() && matrix[r][c] > matrix[r+1][c]){
            ans = max(ans, solve(r+1, c, matrix) + 1);
        }
        // LEFT
        if(c-1 >= 0 && matrix[r][c] > matrix[r][c-1]){
            ans = max(ans, solve(r, c-1, matrix) + 1);
        }
        // RIGHT
        if(c+1 < matrix[0].size() && matrix[r][c] > matrix[r][c+1]){
            ans = max(ans, solve(r, c+1, matrix) + 1);
        }
        
        return t[r][c] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();

        memset(t, -1, sizeof(t)); 
        
        int lis = 1;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                int ans = solve(r, c, matrix);
                lis = max(lis, ans);
            }
        }
        return lis;
    }
};
