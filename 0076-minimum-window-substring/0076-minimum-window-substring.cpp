class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (n > m) return "";

        unordered_map<char, int> mp;   // current window
        unordered_map<char, int> mpp;  // t frequency

        for (char c : t) {
            mpp[c]++;
        }

        int left = 0;
        int count = 0;
        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < m; right++) {

            mp[s[right]]++;

            // Required character found
            if (mpp.count(s[right]) &&
                mp[s[right]] <= mpp[s[right]]) {
                count++;
            }

            // Current window is valid
            while (count == n) {

                // Update answer
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                if (mpp.count(s[left]) &&
                    mp[s[left]] <= mpp[s[left]]) {
                    count--;
                }

                mp[s[left]]--;
                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }

        return s.substr(start, minLen);
    }
};