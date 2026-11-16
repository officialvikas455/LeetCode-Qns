class Solution {
public:
    int countDigits(long long n) {
        if (n == 0) return 1;
        n = abs(n);
        int count = 0;
        while (n > 0) {
            n /= 10;
            count++;
        }
        return count;
    }

    int addDigits(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        if (countDigits(sum) == 1) {
            return sum;
        }
        return addDigits(sum);
    }
};
