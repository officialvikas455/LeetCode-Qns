class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();

        std::unordered_map<char, int> mpp;
        for (char c : s) {
            mpp[c]++;
        }

        std::priority_queue<pair<int, char>> pq;

        for (auto& x : mpp) {
            pq.push({x.second, x.first});
        }
        string ans; // apend vector mien nhi hota

        while (!pq.empty()) {
            auto curr = pq.top();

            int freq = curr.first;
            char ch = curr.second;

            ans.append(freq, ch);
            pq.pop();
        }
        return ans;
    }
};