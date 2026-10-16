#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;

        // 1. Corrected bounds: 0-indexed loops running up to n-1
        for (int left = 0; left < n; left++) {
            long long prod = 1; // 2. Using long long to mitigate overflow
            long long LCM = 1;
            long long GCD = 0;

            for (int right = left; right < n; right++) {
                // Safeguard against overflow before multiplying
                if (prod > LLONG_MAX / nums[right]) {
                    break; // Product is too large to fit in a long long; stop extending this window
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
