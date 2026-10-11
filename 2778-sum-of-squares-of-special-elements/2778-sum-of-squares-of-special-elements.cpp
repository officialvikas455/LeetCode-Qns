class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int prod = 1;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                prod = nums[i-1]*nums[i-1];
                sum += prod;
            }
        }
        return sum;
    }
};