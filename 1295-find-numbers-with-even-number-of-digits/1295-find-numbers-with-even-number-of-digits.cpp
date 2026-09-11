class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for (int num : nums) {
            int digits = 0;
            int temp = num;
            
            // Count digits
            while (temp > 0) {
                digits++;
                temp /= 10;
            }
            
            // If digit count is even, increment counter
            if (digits % 2 == 0) {
                cnt++;
            }
        }
        return cnt;
    }
};
