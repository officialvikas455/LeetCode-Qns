class Solution {
public:
    int t[501];

    int solve(vector<int>& arr, int k, int i) {
        if (i >= arr.size())
            return 0;
            
        if (t[i] != -1)
            return t[i];

        int currMax = 0;
        int res = 0;
        for (int j = i; j < arr.size() && j - i + 1 <= k; j++) {
            currMax = max(currMax, arr[j]);
            res = max(res, ((currMax * (j - i + 1)) + solve(arr, k, j + 1)));
        }
        return t[i] = res;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t, -1, sizeof(t));
        return solve(arr, k, 0);
    }
};