class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> square;
        for(int i=0; i<n; i++){
            int val = 1LL * nums[i] * nums[i];
            square.push_back(val);
        }
        sort(square.begin(), square.end());

    return accumulate(square.begin()+n/2, square.end(),0LL) - accumulate(square.begin(), square.begin()+ n/2,0LL); ;

    }
};