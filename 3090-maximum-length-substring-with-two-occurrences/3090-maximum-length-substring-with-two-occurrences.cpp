class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int left = 0, right = 0;
        int maxLen = 0;

        unordered_map<char, int> count;

        for(int i=0; i<n; i++) {
            count[s[right]]++;
        
            while(count[s[right]] > 2) {
                count[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};