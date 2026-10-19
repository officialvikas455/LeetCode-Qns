class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int &x : nums){
            mp[x]++;
        }
        for(auto &c : mp){
            if(c.second == 1){
                ans.push_back({c.first});
            }
        }
        return ans;
    }
};