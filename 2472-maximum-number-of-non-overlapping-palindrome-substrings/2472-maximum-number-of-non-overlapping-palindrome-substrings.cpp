class Solution {
public:

    int t[2001];
    bool isPalindrome(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int i, int k) {
        int n = s.length();

        if (i >= n)
            return 0;

        if (t[i] != -1)
            return t[i];

        int ans = solve(s, i + 1, k);

        for (int j = i + k - 1; j < n; j++) {

            if (isPalindrome(s, i, j)) {

                ans = max(ans, 1 + solve(s, j + 1, k));
            }
        }

        return t[i] = ans;
    }

    int maxPalindromes(string s, int k) {
        memset(t, -1, sizeof(t));

        return solve(s, 0, k);
    }
};