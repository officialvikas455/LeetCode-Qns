
class Solution {
public:
    void bfs(int src, vector<vector<int>>& adj, vector<bool>& vis, int n) {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &nbr : adj[node]) {
                if (!vis[nbr]) {
                    q.push(nbr);
                    vis[nbr] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (r == c) continue;
                if (isConnected[r][c] == 1) {
                    adj[r].push_back(c);
                }
            }
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                bfs(i, adj, vis, n);
                count++;
            }
        }

        return count;
    }
};