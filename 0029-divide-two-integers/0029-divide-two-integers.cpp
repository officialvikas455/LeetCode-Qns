
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        // Step 1: Determine the sign
        bool negative = (dividend < 0) != (divisor < 0);

        // Step 2: Convert to long long BEFORE taking absolute value
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long quotient = 0;

        // Step 3: Subtract the largest possible multiple
        while (n >= d) {
            int cnt = 0;

            while (n >= (d << (cnt + 1))) {
                cnt++;
            }

            quotient += (1LL << cnt);
            n -= (d << cnt);
        }

        // Step 4: Apply the sign
        if (negative) quotient = -quotient;

        // Step 5: Handle 32-bit integer overflow
        if (quotient > INT_MAX) return INT_MAX;
        if (quotient < INT_MIN) return INT_MIN;

        return (int)quotient;
    }
};
