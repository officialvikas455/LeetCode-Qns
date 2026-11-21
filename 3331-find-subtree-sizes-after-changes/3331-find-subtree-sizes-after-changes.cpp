class Solution {
public:
    unordered_map<int, vector<int>> adj;
    vector<int> resultSize;
    vector<int> last;

    void dfs(int currNode, string &s, vector<int> &parent) {

        int c = s[currNode] - 'a';

        int nearestAncestor = last[c];

        last[c] = currNode;

        for (int child : adj[currNode]) {
            dfs(child, s, parent);
        }

        // Restore previous occurrence while backtracking
        last[c] = nearestAncestor;

        // Update parent of current node
        if (currNode != 0) {
            if (nearestAncestor != -1) {
                parent[currNode] = nearestAncestor;
            }
        }

        // Add current subtree size to its updated parent
        if (currNode != 0) {
            resultSize[parent[currNode]] += resultSize[currNode];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        resultSize.assign(n, 1);
        last.assign(26, -1);

        dfs(0, s, parent);

        return resultSize;
    }
};