// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
//         int n1 = nums1.size();
//         int n2 = nums2.size();

//         for(int i = 0; i < n1; i++){
//             int vikas = nums1[i];

//             int j = 0;

//             // find index in nums2
//             for(j = 0; j < n2; j++){
//                 if(nums2[j] == vikas) break;
//             }

//             int greater = -1;

//             // find next greater
//             for(int k = j + 1; k < n2; k++){
//                 if(nums2[k] > vikas){
//                     greater = nums2[k];
//                     break;
//                 }
//             }

//             ans.push_back(greater);
//         }

//         return ans;
//     }
// };

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mp;

        // Step 1: process nums2
        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                mp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Step 2: build answer for nums1
        vector<int> ans;
        for(int num : nums1){
            if(mp.find(num) != mp.end())
                ans.push_back(mp[num]);
            else
                ans.push_back(-1);
        }

        return ans;
    }
};