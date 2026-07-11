class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        int count[26] = {0};
        
        // Count frequency from s
        for(int i = 0; i < s.length(); i++){
            count[s[i] - 'a']++;
        }
        
        // Decrease frequency using t
        for(int i = 0; i < t.length(); i++){
            int idx = t[i] - 'a';
            count[idx]--;
            if(count[idx] < 0){   // More chars in t than in s
                return false;
            }
        }
        
        return true;  // All matched
    }
};