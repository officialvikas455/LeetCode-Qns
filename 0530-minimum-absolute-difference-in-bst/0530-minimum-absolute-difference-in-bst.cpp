class Solution {
public:
    vector<int> vec;
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        int mn = INT_MAX;
        for(int i=1;i<vec.size();i++)
            mn = min(mn,vec[i]-vec[i-1]);
        return mn;
    }
};