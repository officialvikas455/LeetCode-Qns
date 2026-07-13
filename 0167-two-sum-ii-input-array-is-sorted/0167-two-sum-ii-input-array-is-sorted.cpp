class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0;
        int end = n-1;
        vector<int> ans;

     while(start < end){
            if(numbers[start] + numbers[end]== target){
                ans = {start + 1, end + 1};
                return ans;
            }
            else if(numbers[start] + numbers[end] > target){
                end--;

            }
            else {
                start++;
            }
        }
        return ans;
        
    }
};