class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();

        int ans = 0, cnt = 0;

        for(int i=0; i<s.length(); i++){
               if(s[i] == '(' ){
                cnt++;
            }
            else if(cnt > 0) cnt--;
            else ans++;           
        }
        return ans + cnt;
    }
};