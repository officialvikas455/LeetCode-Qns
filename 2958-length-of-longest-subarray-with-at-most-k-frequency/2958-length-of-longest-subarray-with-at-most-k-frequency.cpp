class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        int st= 0, end= 0;
        unordered_map<int,int> count;

        while(end < n){
            count[nums[end]]++;
            while(count[nums[end]] > k){
                count[nums[st]]--;
                st++;
            }
            len = max(len, end-st+1);
            end++;
        }
        return len;
    }
};