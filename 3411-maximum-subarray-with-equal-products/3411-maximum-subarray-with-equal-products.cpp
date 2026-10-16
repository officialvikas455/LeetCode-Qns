#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        for (int left = 0; left < n; left++) {
            long long prod = 1;
            long long LCM = 1;
            long long GCD = 0;

            for (int right = left; right < n; right++) {
                if (prod > LLONG_MAX / nums[right]) {
                    break;
                }
                
                prod *= nums[right];
                LCM = std::lcm(LCM, (long long)nums[right]);
                GCD = std::gcd(GCD, (long long)nums[right]);

                if (prod == LCM * GCD) {
                    maxLength = max(maxLength, right - left + 1);
                }
            }
        }
        return maxLength;
    }
};
