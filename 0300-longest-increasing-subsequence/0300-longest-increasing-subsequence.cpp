class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> LIS(n,1);
        int res = 1;

        for(int i=1; i<n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
                }
            }
           res = max(LIS[i], res);
        }
        return res;
    }
};