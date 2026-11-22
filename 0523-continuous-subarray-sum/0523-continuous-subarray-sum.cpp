class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        long long sum = 0;
        int count = 0;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = ((sum % k) + k)%k;

            if(mp.find(rem) != mp.end()){
                if(i - mp[rem] >= 2) return true;
            }
            else{
                mp[rem] = i;
            }
        }
        return false;
    }
};