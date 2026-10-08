class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        
        for (char curr : s) {
            if (curr == '(') {
                // If depth > 0, it is not an outermost opening parenthesis
                if (depth > 0) ans += curr;
                depth++;
            } else {
                depth--;
                // If depth > 0, it is not an outermost closing parenthesis
                if (depth > 0) ans += curr;
            }
        }
        return ans;
    }
};