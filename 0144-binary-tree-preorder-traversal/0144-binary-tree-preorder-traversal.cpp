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
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;

        while(root){
            //root left does not exits
            if(!root->left){
                ans.push_back(root->val);
                root= root->right;
            }
            //root left exits
            else{
                TreeNode* curr = root->left;
                while(curr->right && curr->right != root)
                    curr = curr->right;
                    //left subtree not exits
                if(curr->right == NULL){
                    ans.push_back(root->val);
                    curr->right = root;
                    root = root->left;
                }
                else{
                    curr->right = NULL;
                    root= root->right;
                }
            }
        }
        return ans;
    }
};