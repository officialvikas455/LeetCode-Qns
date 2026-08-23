#include <string>
#include <vector>

class Solution {
public:
    bool sumGame(std::string num) {
        int n = num.length();
        double sumDiff = 0;
        double qDiff = 0;

        // Process the first half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                qDiff += 0.5; // Alice and Bob take turns; Bob covers half the value
            } else {
                sumDiff += (num[i] - '0');
            }
        }

        // Process the second half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                qDiff -= 0.5;
            } else {
                sumDiff -= (num[i] - '0');
            }
        }

        // Alice wins if the differences don't perfectly balance out to 0
        return sumDiff + qDiff * 9 != 0;
    }
};
