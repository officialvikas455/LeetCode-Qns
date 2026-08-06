#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int x) {
        int prod = 1;
        while (x > 0) {
            prod *= (x % 10);
            x /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (solve(n) % t == 0)
                return n;
            n++;
        }
    }
};