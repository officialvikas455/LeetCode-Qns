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

// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         unordered_map<int, int> inMap;
//         for (int i = 0; i < inorder.size(); i++) {
//             inMap[inorder[i]] = i;
//         }
//         return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
//     }

// private:
//     TreeNode* build(vector<int>& pre, int preStart, int preEnd, 
//                     vector<int>& in, int inStart, int inEnd, 
//                     unordered_map<int, int>& inMap) {
//         if (preStart > preEnd || inStart > inEnd) return nullptr;

//         TreeNode* root = new TreeNode(pre[preStart]);
//         int inRoot = inMap[root->val];
//         int numsLeft = inRoot - inStart;

//         root->left = build(pre, preStart + 1, preStart + numsLeft, 
//                            in, inStart, inRoot - 1, inMap);
                           
//         root->right = build(pre, preStart + numsLeft + 1, preEnd, 
//                             in, inRoot + 1, inEnd, inMap);

//         return root;
//     }
// };




class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;

        // Start with the first element as the root
        TreeNode* root = new TreeNode(preorder[0]);
        stack<TreeNode*> st;
        st.push(root);
        
        int inIdx = 0; // Tracks our position in the inorder array

        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* curr = st.top();

            // Case 1: Keep extending the left child chain
            if (curr->val != inorder[inIdx]) {
                curr->left = new TreeNode(preorder[i]);
                st.push(curr->left);
            } 
            // Case 2: We hit a leaf node, pop back up to find the correct right child parent
            else {
                while (!st.empty() && st.top()->val == inorder[inIdx]) {
                    curr = st.top();
                    st.pop();
                    inIdx++;
                }
                // Attach the current preorder element as the right child
                curr->right = new TreeNode(preorder[i]);
                st.push(curr->right);
            }
        }

        return root;
    }
};
