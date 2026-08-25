class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        mp[0] = 1;

        int odd = 0;
        int cnt = 0;

        for (int x : nums) {
            if (x % 2 != 0) {
                odd++;
            }

            // Need previous prefix with odd - k
            if (mp.find(odd - k) != mp.end()) {
                cnt += mp[odd - k];
            }

            mp[odd]++;
        }

        return cnt;
    }
};