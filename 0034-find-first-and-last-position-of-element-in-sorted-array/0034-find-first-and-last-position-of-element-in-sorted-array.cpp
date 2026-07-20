// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int n = nums.size();

//         vector<int> ans(2, -1);

//         // first occurrence
//         for(int i = 0; i < n; i++) {
//             if(nums[i] == target) {
//                 ans[0] = i;
//                 break;
//             }
//         }

//         // last occurrence
//         for(int i = n - 1; i >= 0; i--) {
//             if(nums[i] == target) {
//                 ans[1] = i;
//                 break;
//             }
//         }

//         return ans;
//     }
// };


class Solution {
public:

    int firstOcc(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                high = mid - 1; // move left
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    int lastOcc(vector<int>& nums, int target){
        int low = 0, high = nums.size() - 1;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target){
                ans = mid;
                low = mid + 1; // move right
            }
            else if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = firstOcc(nums, target);
        int last = lastOcc(nums, target);

        return {first, last};
    }
};