class Solution {
public:
    string digitSum(string s, int k) {
        if(s.length() <= k) return s;

        string result = "";

        for(int i=0; i<s.length(); i+=k){
            int sum = 0;
            for(int j=i; j<s.length() && j < i + k; j++){
                sum += s[j] - '0';
            }
            result += to_string(sum);
        }
        return digitSum(result,k);
    }
};