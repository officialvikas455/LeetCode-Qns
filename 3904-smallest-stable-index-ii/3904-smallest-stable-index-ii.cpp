class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minIndex(n,0);
        int mini = INT_MAX;

        for(int i = n-1 ; i >=0; i--){
            mini = min(mini , nums[i]);
            minIndex[i] = mini;
        }

        int maxvalue = INT_MIN;

        for(int i=0; i<n; i++){
            maxvalue = max(maxvalue, nums[i]);
            int minValue = minIndex[i];

            if(maxvalue - minValue <= k) return i;
        }
           
           return -1;
    }
};