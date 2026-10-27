class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        // unordered_map<char,int> mp;
        vector<int> mp(26,0);

        for(int i=0; i<s.size(); i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }

        for(const auto &x : mp){
            if(x != 0) return false;
        }
        return true;
    }
};