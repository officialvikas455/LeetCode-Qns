class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

       

        for(int i=0; i<nums.size(); i++){
            int x = nums[i];
             vector<int> temp;

            while(x > 0){
                int digit = x % 10;
                temp.push_back(digit);
                x /= 10;
            }
            reverse(begin(temp), end(temp));

            for(int j=0; j<temp.size(); j++){
                result.push_back(temp[j]);
            }
        }
        return result;
          
    }
};