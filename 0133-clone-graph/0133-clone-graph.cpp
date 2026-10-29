/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

unordered_map<Node*, Node*> mp;

void DFS(Node* node, Node* clone_node) {
    for (Node* n : node->neighbors) {
        if (mp.find(n) == mp.end()) {
            Node* clone = new Node(n->val);
            mp[n] = clone;
            clone_node->neighbors.push_back(clone);

            DFS(n, clone);
        } else {
            clone_node->neighbors.push_back(mp[n]);
        }
    }
}

void BFS(queue<Node*>& que) {
    while (!que.empty()) {
        Node* node = que.front();
        Node* clone_node = mp[node];
        que.pop();

        for (Node* n : node->neighbors) {
            if (mp.find(n) == mp.end()) {
                Node* clone = new Node(n->val);
                mp[n] = clone;
                clone_node->neighbors.push_back(clone);

                que.push(n);
            } else {
                clone_node->neighbors.push_back(mp[n]);
            }
        }
    }
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        mp.clear();

        // clone the given node
        Node* clone_node = new Node(node->val);

        // now clone its neighbours and recursively their neighbours
        //  but if a node reappear , then we do need the access of clone d nodes
        //  so stored them in a. map

        mp[node] = clone_node;
        // DFS(node, clone_node);
        queue<Node*> que;
        que.push(node);
        BFS(que);

        return clone_node;
    }
};