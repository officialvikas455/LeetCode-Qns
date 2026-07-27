class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int x : nums) {
            // Skip duplicates
            if (x == first || x == second || x == third) {
                continue;
            }

            if (x > first) {
                third = second;
                second = first;
                first = x;
            } else if (x > second) {
                third = second;
                second = x;
            } else if (x > third) {
                third = x;
            }
        }

        // If third maximum does not exist, return the maximum
        if (third == LLONG_MIN) {
            return first;
        }

        return third;
    }
};
