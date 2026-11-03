class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));
        int cnt = 0;
        for(int i=0; i<n; i++){
            cnt += abs(nums[i] - maxi);
        }
        return cnt;
    }
};