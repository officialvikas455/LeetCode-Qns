class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen  = INT_MIN;
        int zero = 0;

        while(right < n){

            if(nums[right] == 0) zero++;

            if( zero > k){
                if(nums[left] == 0)
                zero--;
                left++;
            }

            maxLen = max(maxLen , right - left + 1);
            right++;
        }
        return maxLen;
    }
};