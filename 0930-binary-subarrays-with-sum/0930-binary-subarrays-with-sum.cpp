class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        long long sum = 0;
        unordered_map<long long,int>mp;
        mp[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            if(mp.count(sum-goal))
                ans += mp[sum-goal];
                mp[sum]++;
        }
        return ans;
    }
};