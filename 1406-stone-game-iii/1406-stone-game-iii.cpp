#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, vector<int>& stoneValue, vector<int>& dp) {
        int n = stoneValue.size();

        // no stones left
        if (i >= n) return 0;

        if (dp[i] != INT_MIN) return dp[i];

        int take = 0;
        int best = INT_MIN;

        // take 1, 2, or 3 stones
        for (int k = 0; k < 3 && i + k < n; k++) {
            take += stoneValue[i + k];

            best = max(best, take - solve(i + k + 1, stoneValue, dp));
        }

        return dp[i] = best;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> dp(n, INT_MIN);

        int diff = solve(0, stoneValue, dp);

        if (diff > 0) return "Alice";
        if (diff < 0) return "Bob";
        return "Tie";
    }
};