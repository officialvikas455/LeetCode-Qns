class Solution {
public:
    int t[501][501];
    int solve(int l, int r, vector<int>& prefSum) {
        if (l >= r)
            return 0;

        if (t[l][r] != -1)
            return t[l][r];

        int score = 0;

        for (int mid = l; mid <= r - 1; mid++) {

            int leftSum = prefSum[mid] - (l - 1 >= 0 ? prefSum[l - 1] : 0);
            int rightSum = prefSum[r] - prefSum[mid];

            if (leftSum < rightSum) {
                score = max(score, leftSum + solve(l, mid, prefSum));
            } else if (leftSum > rightSum) {
                score = max(score, rightSum + solve(mid + 1, r, prefSum));
            } else {
                score = max({score, leftSum + solve(l, mid, prefSum),
                             rightSum + solve(mid + 1, r, prefSum)});
            }
        }
        return t[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {

        int n = stoneValue.size();
          memset(t, -1, sizeof(t));

        vector<int> prefSum(n, 0);

        prefSum[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            prefSum[i] = prefSum[i - 1] + stoneValue[i];
        }
        return solve(0, n - 1, prefSum);
    }
};