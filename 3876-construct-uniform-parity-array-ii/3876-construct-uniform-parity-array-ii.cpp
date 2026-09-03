class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        
        int minEle = *min_element(nums1.begin(), nums1.end());
        
        // If min Element is Odd then we convert all the array into Odd
        if(minEle % 2 == 1){
            return true;
        }
        
        
        for(int &num : nums1){
            if(num % 2 == 1) return false;
        }
        return true;
        
    }
};