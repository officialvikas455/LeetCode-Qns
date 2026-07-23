class Solution {
public:
   bool f( int n, int k, vector<int>& nums){
    vector<bool> prev(k+1,0), curr(k+1,0);

    prev[0] = curr[0] = true;

    if(nums[0] <= k ) {
        prev[nums[0]]= true;
    }

    for(int i=1; i<n; i++){
        for(int target = 1; target <= k; target++){
            bool notTake = prev[target];
            bool take = false;

            if(nums[i] <= target) take = prev[target-nums[i]];
            curr[target] = take || notTake;

        }
        prev = curr;
    }
    return prev[k];
   }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;

      for(int i=0; i<n; i++)  totSum += nums[i];
      if(totSum % 2 != 0 ) return false;
      int target = totSum/2;

      return f(n, target, nums);
        
    }
};