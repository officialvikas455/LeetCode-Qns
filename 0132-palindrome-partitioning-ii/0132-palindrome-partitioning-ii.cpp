class Solution {
public:
    int dp[2001][2001];
    
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    
    int solve(int idx, int n, string &s) {
        if (idx == n) return 0;
        if (dp[idx][n] != -1) return dp[idx][n];
        
        int minCost = INT_MAX;
        for (int j = idx; j < n; j++) {
            if (isPalindrome(s, idx, j)) {
                int cost = 1 + solve(j + 1, n, s);
                minCost = min(cost, minCost);
            }
        }
        return dp[idx][n] = minCost;
    }
    
    int minCut(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.size();
        return solve(0, n, s) - 1;
    }
};
