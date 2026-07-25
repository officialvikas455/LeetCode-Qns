class Solution {
public:
    bool isprime(int n) {
        if (n < 2) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    bool ispalindrom(int n) {
        int original = n;
        int rev = 0;

        while (n) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }

        return rev == original;
    }

    int primePalindrome(int n) {
        if (n >= 8 && n <= 11) return 11;

        for (int i = n; ; i++) {
            if (10000000 <= i && i < 100000000) {
                i = 99999999;
                continue;
            }

            if (isprime(i) && ispalindrom(i)) {
                return i;
            }
        }
    }
};