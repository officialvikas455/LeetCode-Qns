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

// Constructor: O(h) (height of tree)
// next(): Amortized O(1)
// hasNext(): O(1)
// Space: O(h)
class BSTIterator {
private:
    stack<TreeNode*> st;

    //leftmost node tak sabhi nodes stack mein push karo
    void pushAll(TreeNode* node) {

        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }

    bool hasNext() {

        return !st.empty();
    }
};