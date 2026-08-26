class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();

        int l = 0;
        int ones = 0;

        string ans = "";

        for (int r = 0; r < n; r++) {

            // count 1s
            if (s[r] == '1') {
                ones++;
            }
            while (ones == k) {

                string curr = s.substr(l, r - l + 1);

                // first valid substring
                if (ans == "") {
                    ans = curr;
                }
                // shorter substring
                else if (curr.length() < ans.length()) {
                    ans = curr;
                }
                // same length -> lexicographically smaller
                else if (curr.length() == ans.length() && curr < ans) {
                    ans = curr;
                }

                // move left
                if (s[l] == '1') {
                    ones--;
                }

                l++;
            }
        }

        return ans;
    }
};