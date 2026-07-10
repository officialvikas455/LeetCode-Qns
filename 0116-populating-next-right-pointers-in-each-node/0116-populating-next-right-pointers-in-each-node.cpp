/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                if (frontNode->left) {
                    frontNode->left->next = frontNode->right;

                    if (frontNode->next)
                        frontNode->right->next = frontNode->next->left;
                    else
                        frontNode->right->next = NULL;

                    q.push(frontNode->left);
                    q.push(frontNode->right);
                }
            }
        }

        return root;
    }
};