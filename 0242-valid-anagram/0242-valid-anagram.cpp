class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());

        // return s == t;
        unordered_map<char, int> mpp;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
            mpp[t[i]]--;
        }

        for(auto &it : mpp){
            if(it.second != 0) return false;
        }
        return true;  
    }
};