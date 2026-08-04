// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> ans;
//         int n = nums.size();

//         int start = nums[0];
//         int end = nums[n-1];

//         unordered_map<int, int> mpp;
//         for(int i = 0; i<n; i++){
//             mpp[nums[i]];
//         }

//         for(int i = start; i<=end; i++){
//             if(mpp.find(i) == mpp.end()){
//                 ans.push_back(i);
//             }
//         }

//         return ans;
//     }
// };


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> ans;

        for (int i = mn; i <= mx; i++) {
            if (!st.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};