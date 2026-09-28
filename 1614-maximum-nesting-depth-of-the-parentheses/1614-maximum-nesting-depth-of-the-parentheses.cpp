class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, curr = 0;
        for(auto it : s){
            if(it == '('){
                curr++;
                ans = max(curr, ans);
            }else if(it == ')'){
                curr--;
            }
        }
        return ans;
    }
};