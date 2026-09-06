

class Solution {
public:
    int memo[1001][1001];
    
    int solve(int i, int j, string &s, string &t) {
        // If string t is fully matched
        if (j < 0) return 1;
        // If string s is exhausted but t is not
        if (i < 0) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s[i] == t[j]) {
            // Pick the character or skip it in s
            return memo[i][j] = solve(i - 1, j - 1, s, t) + solve(i - 1, j, s, t);
        }
        
        // Skip character in s
        return memo[i][j] = solve(i - 1, j, s, t);
    }
    
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        memset(memo, -1, sizeof(memo));
        return solve(n - 1, m - 1, s, t);
    }
};
