// class Solution {
// public:
//     int missingInteger(vector<int>& nums) {
//         int n = nums.size();
//         int sum = nums[0];
//         for(int i=1; i<n; i++){
//             if(nums[i-1] + 1 == nums[i]){
//                 sum += nums[i];
//             }
//             else{
//                 break;
//             }
//         }
//         unordered_set<int> st(nums.begin(), nums.end());

//         while(st.count(sum)){
//             sum++;
//         }
//         return sum;
        
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else
                break;
        }

        sort(nums.begin(), nums.end());
         int x = sum;
        for (int num : nums) {
            if (num == x) {
                x++;
            }
        }

        return x;
    }
};