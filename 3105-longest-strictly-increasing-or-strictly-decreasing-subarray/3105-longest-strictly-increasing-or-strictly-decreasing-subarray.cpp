class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int mini = 1;
        int maxi = 1;

        for(int i = 0; i < n; i++) {
            int inc = 1, dec = 1;

            for(int j = i + 1; j < n; j++) {

                if(nums[j] > nums[j-1]) {
                    inc++;
                }
                else {
                    inc = 1;
                }

                if(nums[j] < nums[j-1]) {
                    dec++;
                }
                else {
                    dec = 1;
                }

                maxi = max(maxi, inc);
                mini = max(mini, dec);
            }
        }

        return max(mini, maxi);
    }
};