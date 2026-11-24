class Solution {
public:
    int findGcd(int a, int b){
        if(b==0) return a;
        return gcd(b, a%b);
    }
    long long findLcm(long long a, long b){
        return (a*b)/gcd(a,b);
    }
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0; i<n; i++){
            long long prod = 1;
            long long gcd = 0;
            long long lcm = 1;

            for(int j=i; j<n; j++){
                if(prod > LLONG_MAX/nums[j]) break;
                prod *= nums[j];
                lcm = findLcm(lcm,(long long)nums[j]);
                gcd = findGcd(gcd,(long long)nums[j]);

                if(prod == lcm*gcd){
                    maxi = max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};