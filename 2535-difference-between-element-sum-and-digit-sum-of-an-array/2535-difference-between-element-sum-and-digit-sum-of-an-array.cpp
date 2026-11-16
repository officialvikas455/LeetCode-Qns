class Solution {
public:
    int digitSum(long long n){
        if(n == 0) return 1;
        int sum = 0;
        while(n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size();
        int elementS = std::accumulate(begin(nums), end(nums), 0);
        int digitSumBro = 0;

        for(int i=0; i<n; i++){
             digitSumBro += digitSum(nums[i]);

        }
        return abs(elementS - digitSumBro);
    }
};