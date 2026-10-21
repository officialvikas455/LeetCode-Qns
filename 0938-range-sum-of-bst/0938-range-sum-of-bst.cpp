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
  int inorder(TreeNode* root, int low, int high){
    if(root == NULL) return NULL;
    //within range 
    if(root->val >= low && root->val <= high){
        return root->val + inorder(root->left, low, high)
                         + inorder(root->right, low, high);
    }

    if(root->val < low){
        return inorder(root->right, low, high);
    }
    return inorder(root->left, low, high);
 }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return inorder(root, low, high);
    }
};