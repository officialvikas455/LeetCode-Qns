class Solution {
public:

    struct Compare {
        bool operator()(pair<int,int>& a, pair<int,int>& b) {

            if(a.first == b.first) {
                return a.second < b.second; // larger number first
            }

            return a.first > b.first; // smaller frequency first
        }
    };

    vector<int> frequencySort(vector<int>& nums) {

        unordered_map<int, int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            Compare
        > pq;

        vector<int> ans;

        for(auto &y : mp) {
            pq.push({y.second, y.first});
        }

        while(!pq.empty()) {

            auto u = pq.top();
            pq.pop();

            int freq = u.first;
            int num = u.second;

            for(int i = 0; i < freq; i++) {
                ans.push_back(num);
            }
        }

        return ans;
    }
};