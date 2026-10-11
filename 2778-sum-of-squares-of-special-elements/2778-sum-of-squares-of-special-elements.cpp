class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int prod = 1;

        for (int i = 0; i < n; i++) {
            if (n % (i+1) == 0) {
                prod = nums[i]*nums[i];
                sum += prod;
            }
        }
        return sum;
    }
};