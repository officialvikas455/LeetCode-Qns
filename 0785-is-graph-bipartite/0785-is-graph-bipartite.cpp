class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);
        queue<int> q;

        for(int i = 0; i < n; i++) {

            if(color[i] == -1) {

                color[i] = 0;
                q.push(i);

                while(!q.empty()) {

                    int curr = q.front();
                    q.pop();

                    for(int neigh : graph[curr]) {

                        // Not colored yet
                        if(color[neigh] == -1) {

                            // Give opposite color
                            color[neigh] = ! color[curr];

                            q.push(neigh);
                        }

                        // Already colored
                        else {
                            // Same color -> not bipartite
                            if(color[neigh] == color[curr]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};