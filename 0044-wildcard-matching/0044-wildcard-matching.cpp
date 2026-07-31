#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool matched(int m, int n, string &s, string &p,
                 vector<vector<int>> &dp) {
        if (m == 0 && n == 0) return true;
        if (n == 0) return false;

        if (m == 0) {
            for (int k = 0; k < n; k++) {
                if (p[k] != '*') return false;
            }
            return true;
        }

        if (dp[m][n] != -1) return dp[m][n];

        if (p[n - 1] == '?') {
            return dp[m][n] = matched(m - 1, n - 1, s, p, dp);
        }
        else if (p[n - 1] == '*') {
            return dp[m][n] =
                matched(m, n - 1, s, p, dp) ||   // '*' matches empty
                matched(m - 1, n, s, p, dp);    // '*' matches one char
        }
        else if (s[m - 1] == p[n - 1]) {
            return dp[m][n] = matched(m - 1, n - 1, s, p, dp);
        }

        return dp[m][n] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return matched(m, n, s, p, dp);
    }
};