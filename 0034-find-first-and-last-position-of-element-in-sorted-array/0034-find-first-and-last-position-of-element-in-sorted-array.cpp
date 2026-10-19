class Solution {
public:
     int firstOccur(vector<int>& nums, int target){
         int low = 0, high = nums.size()-1;

         int ans = -1;

         while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                 low = mid+1;
            }
            else{
                high = mid-1;
            }
         }
         return ans;
     }
     int lastOccur(vector<int>& nums, int target){
         int low = 0, high = nums.size()-1;

         int ans = -1;

         while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                ans = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){
                 low = mid+1;
            }
            else{
                high = mid-1;
            }
         }
        return ans;
     }
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstOccur(nums,target);
        int last = lastOccur(nums,target);

        return {first, last};
    }
};