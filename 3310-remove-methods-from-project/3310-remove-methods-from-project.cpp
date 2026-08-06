#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);
        vector<bool> suspicious(n, false);

        // Build graph
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        // BFS from k
        queue<int> que;
        que.push(k);
        suspicious[k] = true;

        while (!que.empty()) {
            int curr = que.front();
            que.pop();

            for (int ngbr : adj[curr]) {
                if (!suspicious[ngbr]) {
                    suspicious[ngbr] = true;
                    que.push(ngbr);
                }
            }
        }

        // If a suspicious node has an incoming edge
        // from a non-suspicious node, we cannot remove them
        bool cannotRemove = false;

        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!suspicious[u] && suspicious[v]) {
                cannotRemove = true;
                break;
            }
        }

        // Return all methods if removal is impossible
        if (cannotRemove) {
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                vec.push_back(i);
            }
            return vec;
        }

        // Otherwise return remaining (non-suspicious) methods
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                result.push_back(i);
            }
        }

        return result;
    }
};