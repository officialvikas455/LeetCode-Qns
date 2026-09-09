class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;
        long long comma = 1;
        long long lower = 1000;

        while( lower <= n){
            long long upper = (lower * 1000) - 1;
            if(upper > n) upper = n;

            long long countNo = upper - lower + 1;

            result += (countNo * comma);
            lower = lower * 1000;
            comma += 1;
        }
        return result;
    }
};