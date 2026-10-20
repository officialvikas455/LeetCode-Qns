class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());
        vector<int> divisors;

        for(int i=1; i*i <= n; i++){
            if(n % i == 0){
                divisors.push_back(i);
                if(i != n/i) divisors.push_back(n/i);
            }
        }
        int ans = 0;

        for(int x : divisors){
            bool flag = true;

            for(int i=0; i<n && flag; i+=x){
                int desc = 0, pos = -1;
                for(int j=0; j<x; j++){
                    int a = nums[i+j];
                    int b = nums[i + (j+1) % x ];
                    if(a > b){
                        desc++;
                        pos = j;
                        if(desc > 1) break;
                    }
                }
                if (desc > 1) {
                    flag = false;
                    break;
                }
                int r = (desc == 0) ? 0 : (pos + 1) % x;
                for(int j=0; j<x; j++){
                    if(nums[i + (r + j) % x] != temp[i+j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) ans += x;
        }
        return ans;
    }
};