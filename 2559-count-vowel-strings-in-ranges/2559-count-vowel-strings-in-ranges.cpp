class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> pref(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            bool startsAndEndsWithVowel = isVowel(words[i][0]) && isVowel(words[i].back());
            pref[i + 1] = pref[i] + (startsAndEndsWithVowel ? 1 : 0);
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            ans.push_back(pref[r + 1] - pref[l]);
        }

        return ans;
    }
};
