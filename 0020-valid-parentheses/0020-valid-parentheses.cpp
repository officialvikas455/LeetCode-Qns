class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                }
                char topEle = st.top();
                st.pop();
                if (ch == ')' && topEle != '(') return false;
                if (ch == ']' && topEle != '[') return false;
                if (ch == '}' && topEle != '{') return false;
            }
        }
        return st.empty();
    }
};
