class Solution {
public:
    int maxDepth(string s) {
     int cnt = 0;
     int maxi = 0;
     for(int i=0; i<s.length(); i++){
        if(s[i] == '(') {
            cnt++;
            if(maxi < cnt) maxi = cnt;
        }
        else if (s[i] == ')') cnt--;
     }
     return maxi;
    }
};