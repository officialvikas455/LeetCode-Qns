// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     static bool compare(vector<int>& first, vector<int>& second) {
//         if (first[0] == second[0]) {
//             return first[1] < second[1];
//         }
//         return first[0] < second[0];
//     }

//     int maxEnvelopes(vector<vector<int>>& envelopes) {
//         sort(envelopes.begin(), envelopes.end(), compare);

//         int n = envelopes.size();
//         vector<int> LIS(n, 1);

//         int maxLen = 1;

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < i; j++) {

//                 if (envelopes[i][0] > envelopes[j][0] &&
//                     envelopes[i][1] > envelopes[j][1]) {

//                     LIS[i] = max(LIS[i], 1 + LIS[j]);
//                 }
//             }

//             maxLen = max(maxLen, LIS[i]);
//         }

//         return maxLen;
//     }
// };




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(vector<int>& first, vector<int>& second) {
        if (first[0] == second[0]) {
            return first[1] > second[1];
        }
        return first[0] < second[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);

        int n = envelopes.size();
        vector<int> temp(1,envelopes[0][1]);


        for(int i=1; i<n; i++){
            int index = lower_bound(temp.begin(), temp.end(), envelopes[i][1])  - temp.begin();

            if(index == temp.size()){
                temp.push_back(envelopes[i][1] );
            }
            else{
                temp[index] = envelopes[i][1] ;
            }
        }
       
       return temp.size();
    }
};