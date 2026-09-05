class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int mn = INT_MAX;
        vector<int> minFromIndex(n,0);

        for(int i = n-1; i>=0; i--){
            mn = min(mn, nums[i]);
            minFromIndex[i] = mn;
        }
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
          maxi = max(maxi, nums[i]);
          int minEle = minFromIndex[i];

          if(maxi - minEle <= k) return i;
          
        }
        return -1;
    }
};