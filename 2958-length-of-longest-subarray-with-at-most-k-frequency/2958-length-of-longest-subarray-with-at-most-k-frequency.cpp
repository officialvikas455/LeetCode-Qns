class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int st = 0, end = 0, len = 0;

        unordered_map<int, int> freq;

        for(int i=0; i<n; i++){
            freq[nums[end]]++;


            while(freq[nums[end]] > k){
                freq[nums[st]]--;
                st++;
            }
            len = max(len, end-st+1);
            end++;
        }
        return len;
    }
};