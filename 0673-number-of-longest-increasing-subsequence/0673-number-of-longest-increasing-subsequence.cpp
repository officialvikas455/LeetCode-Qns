class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        vector<int> count(n,1);
        int result = 0;

        int maxlen = 1;

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]){
                    if(LIS[i] < 1 + LIS[j]){
                        LIS[i] = 1 + LIS[j];
                        count[i] = count[j];

                    }else if(LIS[i] == 1 + LIS[j]){
                        count[i] += count[j];
                    }
                }
            }
            maxlen = max(maxlen, LIS[i]);
        }
        for(int i=0; i<n; i++){
            if(maxlen == LIS[i]){
                result += count[i];
            }
        }
        return result;
    }
};