class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> LDS(n,1);
        vector<int> parent(n,-1);

        int maxLen = 1, index = 0;

        for(int i=0; i<n; i++){
            for(int j=0;j<i; j++){
                if(nums[i] % nums[j] == 0){
                    if(LDS[i] < 1 + LDS[j]){
                        LDS[i] = 1 + LDS[j];
                        parent[i] = j;
                    }
                }
            }
            if(maxLen < LDS[i]){
            maxLen = LDS[i];
            index = i;
       }

    }
       
       vector<int> ans;

       while(index != -1){
        ans.push_back(nums[index]);
        index = parent[index];
       }

       reverse(ans.begin(), ans.end());

       return ans;

    }
};