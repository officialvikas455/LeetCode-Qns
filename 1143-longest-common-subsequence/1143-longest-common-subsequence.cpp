
class Solution {
public:
    int t[1001][10001];

    int solve(int i, int j, string &text1, string &text2) {

        if(i == 0 || j == 0) return 0;

        if(t[i][j] != -1)
            return t[i][j];

        int ans1 = 0, ans2 = 0;

        if(text1[i-1] == text2[j-1]) {

            ans1 = 1 + solve(i-1, j-1, text1, text2);

        } 
        else {

            ans2 = max(
                solve(i-1, j, text1, text2),
                solve(i, j-1, text1, text2)
            );
        }

        return t[i][j] = max(ans1, ans2);
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n = text1.size();
        int m = text2.size();

        memset(t, -1, sizeof(t));

        return solve(n, m, text1, text2);
    }
};
