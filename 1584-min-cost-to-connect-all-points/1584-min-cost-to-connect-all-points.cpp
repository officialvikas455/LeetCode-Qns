
class Solution {
public:
    typedef pair<int, int> T;

    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();

        priority_queue<T, vector<T>, greater<T>> pq;

        vector<bool> MST(V, 0);

        int src = 0;

        pq.push({0, src});

        int minCost = 0;
        int count = 0;

        while(!pq.empty()) {

            int U = pq.top().second;
            int cost = pq.top().first;

            pq.pop();

            if(MST[U]) continue;

            MST[U] = true;
            minCost += cost;
            count++;

            if(count == V) break;

            for(int i = 0; i < V; i++) {

                if(!MST[i]) {

                    int wt = abs(points[U][0] - points[i][0])
                           + abs(points[U][1] - points[i][1]);

                    pq.push({wt, i});
                }
            }
        }

        return minCost;
    }
};
