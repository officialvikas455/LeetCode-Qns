class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Agar tree empty hai to empty answer return kar do.
        if(root == NULL)
            return {};

        vector<vector<int>> result;

        // Level Order Traversal ke liye Queue use karenge.
        queue<TreeNode*> q;
        q.push(root);

        // Starting direction Left -> Right rahegi.
        bool leftToRight = true;

        while(!q.empty()){

            // Current level me kitne nodes hain.
            int size = q.size();

            // Current level ke answer ko store karne ke liye vector.
            vector<int> ans(size);

            // Current level ke sabhi nodes ko process karenge.
            for(int i = 0; i < size; i++){

                TreeNode* frontNode = q.front();
                q.pop();

                // Agar Left -> Right hai to normal index use hoga.
                // Agar Right -> Left hai to reverse index use hoga.
                int idx = leftToRight ? i : size - i - 1;

                ans[idx] = frontNode->val;

                // Next level ke nodes ko queue me add kar do.
                if(frontNode->left)
                    q.push(frontNode->left);

                if(frontNode->right)
                    q.push(frontNode->right);
            }

            // Current level ka answer final result me add kar do.
            result.push_back(ans);

            // Har level ke baad traversal direction change kar do.
            leftToRight = !leftToRight;
        }

        return result;
    }
};