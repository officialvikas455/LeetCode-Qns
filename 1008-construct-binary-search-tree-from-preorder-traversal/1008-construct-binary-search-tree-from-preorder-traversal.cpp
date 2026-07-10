/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 
  TreeNode* solve(TreeNode* root, int x) {
        if (root == NULL)
            return new TreeNode(x);

        if (x > root->val)
            root->right = solve(root->right, x);
        else
            root->left = solve(root->left, x);

        return root;
    }
     
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;

        for(int i=0; i<preorder.size(); i++){
            root = solve(root,preorder[i]);
        }
        return root;
    }
};