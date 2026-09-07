class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);

            int sz = mp[nums[i]].size();

            // Need at least 3 occurrences
            if (sz >= 3) {
                int a = mp[nums[i]][sz - 3];
                int c = mp[nums[i]][sz - 1];

                int distance = 2 * (c - a);
                ans = min(ans, distance);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};