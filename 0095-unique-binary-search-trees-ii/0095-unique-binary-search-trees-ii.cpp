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
 vector<TreeNode*> solve(int st, int end){
    if(st>end) return {NULL};

    if(st == end) {
        TreeNode* root = new TreeNode(st);
        return {root};
    }
    vector<TreeNode*> result;
    for(int i = st; i<= end; i++){
      vector<TreeNode*> left_BSTs=  solve(st, i-1);
      vector<TreeNode*> right_BSTs= solve(i+1,end);
    
      for(TreeNode* leftRoot : left_BSTs){
        for(TreeNode* rightRoot : right_BSTs){
           TreeNode* root = new TreeNode(i);
           root->left = leftRoot;
           root->right = rightRoot;

           result.push_back(root);
        }
      }

    }
    return result;

 }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1,n);
    }
};