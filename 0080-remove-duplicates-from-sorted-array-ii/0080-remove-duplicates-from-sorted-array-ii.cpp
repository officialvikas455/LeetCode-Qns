class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if(n <= 2) return n;

    int ans = 2; 

    for(int i = 2; i < n; i++){
        if(nums[i] != nums[ans - 2]){
            nums[ans] = nums[i];
            ans++;
        }
    }
    return ans;
}
};