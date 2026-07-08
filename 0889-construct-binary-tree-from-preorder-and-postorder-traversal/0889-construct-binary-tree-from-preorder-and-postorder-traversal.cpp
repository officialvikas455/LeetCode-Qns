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
    TreeNode* solve(vector<int>& preorder, vector<int>& postorder,
                    int &preIdx, int &postIdx) {

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        // If current subtree is not finished in postorder,
        // then left child exists.
        if (root->val != postorder[postIdx])
            root->left = solve(preorder, postorder, preIdx, postIdx);

        // After building left, if still not finished,
        // then right child exists.
        if (root->val != postorder[postIdx])
            root->right = solve(preorder, postorder, preIdx, postIdx);

        // Current subtree is complete.
        postIdx++;

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {

        int preIdx = 0;
        int postIdx = 0;

        return solve(preorder, postorder, preIdx, postIdx);
    }
};