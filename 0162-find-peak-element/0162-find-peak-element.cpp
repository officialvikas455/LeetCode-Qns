// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
//         int n = nums.size();

//         int l = 0, r = n-1;

//         while(l < r){
//           int mid = l + (r-l)/2;

//           if(nums[mid] > nums[mid+1])
//                r = mid;
//           else 
//             l = mid + 1;

//           return l;

//         // for(int i = 0; i < n; i++) {
//         //     bool left = (i == 0) || (nums[i] > nums[i - 1]);
//         //     bool right = (i == n - 1) || (nums[i] > nums[i + 1]);

//         //     if(left && right) return i;
//         // }
//         // return -1;
//         }
//     }
// };


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while(low < high) {
            int mid = (low + high) / 2;

            if(nums[mid] > nums[mid + 1]) {
                high = mid;   // peak is on left
            } else {
                low = mid + 1; // peak is on right
            }
        }
        return low;
    }
};