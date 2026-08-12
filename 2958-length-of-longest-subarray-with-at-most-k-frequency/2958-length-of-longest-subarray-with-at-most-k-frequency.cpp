class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0, end = 0;
        int len = 0;
        unordered_map<int,int> cnt;
        
        while(end < n){
           cnt[nums[end]]++;

           while(cnt[nums[end]] > k){
             cnt[nums[st]]--;
             st++;
           }
           len = max(len, end-st+1);
           end++;
        }
        
        return len;
    }
};