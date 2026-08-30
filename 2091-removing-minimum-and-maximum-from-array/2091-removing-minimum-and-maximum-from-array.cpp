class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minEIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxEIdx = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(minEIdx, maxEIdx);

        int right = max(minEIdx, maxEIdx);

        return min({left+1+n-right, right+1, n-left});
        
    }
};