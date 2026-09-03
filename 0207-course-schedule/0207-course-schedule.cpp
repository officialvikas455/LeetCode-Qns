class Solution {
public:

    bool topo(unordered_map<int, vector<int>> &adj,
              int n,
              vector<int> &indegree) {

        queue<int> que;

        int count = 0;

        // Nodes with indegree 0
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                que.push(i);
            }
        }

        while(!que.empty()) {

            int u = que.front();
            que.pop();

            count++;

            for(int &v : adj[u]) {

                indegree[v]--;

                if(indegree[v] == 0) {
                    que.push(v);
                }
            }
        }

        return count == n;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        unordered_map<int, vector<int>> adj;
        vector<int> indegree(numCourses, 0);

        for(auto &vec : prerequisites) {

            int a = vec[0];
            int b = vec[1];

            // b ---> a
            adj[b].push_back(a);

            // edge is going INTO a
            indegree[a]++;
        }

        // If cycle exists -> cannot finish
        return topo(adj, numCourses, indegree);
    }
};