// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int n = arr.size();
//         int left = 0;
//         int sum = 0;
//         int mini = INT_MAX;
//         int cnt = 0;

//         for(int right=0; right< n; right++){
//             sum += arr[right];

//             while(sum == target){
//              mini += min(mini, right-left+1);
//              right++;
//             }
//             arr[left]--;
//             left++;
//         }
//         return cnt;
//     }
// };


class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int mini = INT_MAX;

        for(int right = 0; right < n; right++) {
            sum += arr[right];

            while(sum > target) {
                sum -= arr[left];
                left++;
            }

            if(sum == target) {
                int len = right - left + 1;

                if(left > 0 && best[left - 1] != INT_MAX) {
                    mini = min(mini, len + best[left - 1]);
                }

                if(left > 0)
                    best[right] = min(best[right - 1], len);
                else
                    best[right] = len;
            }
            else {
                if(right > 0)
                    best[right] = best[right - 1];
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};