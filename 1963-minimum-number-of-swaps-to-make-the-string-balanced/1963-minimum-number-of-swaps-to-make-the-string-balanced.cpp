class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        int size = 0;

        for(char &ch : s){
            if(ch == '[') st.push(ch);
            else if(st.empty()) size++;
            else st.pop();
        }
        return (st.size() + 1)/2;
    }
};