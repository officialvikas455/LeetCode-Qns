class Solution {
public:
     TreeNode* helper(vector<int>&nums, int st, int end){
        if(st > end) return NULL;
        int mid = st +(end-st)/2;

        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, st, mid-1);
        root->right = helper(nums, mid+1, end);

        return root;
     }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int st = 0; 
        int end= n-1;
        return helper(nums, 0, n-1);
        
    }
};
