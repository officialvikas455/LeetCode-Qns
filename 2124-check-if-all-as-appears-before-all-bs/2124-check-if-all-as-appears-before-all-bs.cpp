class Solution {
public:
    bool checkString(string s) {
        int n = s.length();
        bool seenB = false;

        for(char c : s){
            if(c == 'b'){
                seenB=true;
            }else if(seenB){
                return false;
            }
        }
        return true;
    }
};