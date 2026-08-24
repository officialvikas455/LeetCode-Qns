// class Solution {
// public:
//     int n;

//     int solve(vector<int>& stones) {
//         vector<int> res;

//         int currSum = 0;

//         for (int i = 0; i < n; i++) {
//             currSum += stones[i];
//             res.push_back(currSum);
//         }

//         int ans = res[n - 1];

//         for (int i = n - 2; i >= 1; i--) {
//             ans = max(ans, res[i] - ans);
//         }

//         return ans;
//     }

//     int stoneGameVIII(vector<int>& stones) {
//         n = stones.size();

//         return solve(stones);
//     }
// };



class Solution {
public:
    int n;

    int solve(vector<int>& stones) {
        vector<int> res;

        int currSum = 0;
        for (int i = 0; i < n; i++) {
            currSum += stones[i];
            res.push_back(currSum);
        }

        int ans1 = res[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            int ans2 = res[i] - ans1;
            ans1 = max(ans1, ans2);
        }

        return ans1;
    }

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        return solve(stones);
    }
};