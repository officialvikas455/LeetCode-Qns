// #include <string>
// #include <vector>

// class Solution {
// public:
//     bool sumGame(std::string num) {
//         int n = num.length();
//         double sumDiff = 0;
//         double qDiff = 0;

//         // Process the first half
//         for (int i = 0; i < n / 2; i++) {
//             if (num[i] == '?') {
//                 qDiff += 0.5; // Alice and Bob take turns; Bob covers half the value
//             } else {
//                 sumDiff += (num[i] - '0');
//             }
//         }

//         // Process the second half
//         for (int i = n / 2; i < n; i++) {
//             if (num[i] == '?') {
//                 qDiff -= 0.5;
//             } else {
//                 sumDiff -= (num[i] - '0');
//             }
//         }

//         // Alice wins if the differences don't perfectly balance out to 0
//         return sumDiff + qDiff * 9 != 0;
//     }
// };



#include <string>
#include <vector>

class Solution {
public:
    bool sumCheck(int leftSum, int rightSum, int leftQ, int rightQ) {
        // Bob wants to balance the sums. 
        // Every 2 remaining '?' marks can bridge a gap of 9 points.
        int sumDelta = leftSum - rightSum;
        int qDelta = rightQ - leftQ;
        
        return (2 * sumDelta == 9 * qDelta);
    }

    bool sumGame(std::string num) {
        int n = num.length();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        // Your idea of looping, fixed to correctly read the string characters
        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?') leftQ++;
                else leftSum += (num[i] - '0');
            } else {
                if (num[i] == '?') rightQ++;
                else rightSum += (num[i] - '0');
            }
        }

        // If Bob can balance it, Alice loses (returns false).
        // If Bob cannot balance it, Alice wins (returns true).
        if (sumCheck(leftSum, rightSum, leftQ, rightQ)) {
            return false; 
        }
        
        return true;
    }
};

