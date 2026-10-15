
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int result = 0;

        for (int left = 0; left < n; left++) {
            unordered_map<int, int> mp;

            for (int right = left; right < n; right++) {
                mp[nums[right]]++;

                int distinct = mp.size();
                result += distinct * distinct;
            }
        }

        return result;
    }
};
