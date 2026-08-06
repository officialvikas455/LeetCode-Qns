// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     int solve(int x) {
//         int prod = 1;
//         while (x > 0) {
//             prod *= (x % 10);
//             x /= 10;
//         }
//         return prod;
//     }

//     int smallestNumber(int n, int t) {
//         while (true) {
//             if (solve(n) % t == 0)
//                 return n;
//             n++;
//         }
//     }
// };



class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            vector<int> dig;
            int temp = n;

            // store all digits
            while (temp > 0) {
                dig.push_back(temp % 10);
                temp /= 10;
            }

            // product of digits
            int prod = 1;
            for (int i = 0; i < dig.size(); i++) {
                prod *= dig[i];
            }

            if (prod % t == 0)
                return n;

            n++;
        }
    }
};