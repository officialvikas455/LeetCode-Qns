class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int l = 0, r = 0;
        int len = 0;

        unordered_map<char, int> mpp;

        while(r < n) {

            mpp[s[r]]++;

            while(mpp[s[r]] > 1) {
                mpp[s[l]]--;
                l++;
            }

            len = max(len, r - l + 1);

            r++;
        }

        return len;
    }
};