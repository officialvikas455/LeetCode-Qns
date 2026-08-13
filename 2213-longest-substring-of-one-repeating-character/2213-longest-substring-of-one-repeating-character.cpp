class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();

        // segments: {start, end}
        set<pair<int,int>> seg;
        multiset<int> lens;

        // build initial segments
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && s[j] == s[i]) j++;

            seg.insert({i, j - 1});
            lens.insert(j - i);
        }

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {
            int idx = queryIndices[q];
            char ch = queryCharacters[q];

            if (s[idx] == ch) {
                ans.push_back(*lens.rbegin());
                continue;
            }

            // find segment containing idx
            auto it = prev(seg.upper_bound({idx, n}));
            auto [l, r] = *it;

            seg.erase(it);
            lens.erase(lens.find(r - l + 1));

            // left part
            if (l <= idx - 1) {
                seg.insert({l, idx - 1});
                lens.insert(idx - l);
            }

            // right part
            if (idx + 1 <= r) {
                seg.insert({idx + 1, r});
                lens.insert(r - idx);
            }

            s[idx] = ch;

            int nl = idx, nr = idx;

            // merge left
            auto cur = seg.lower_bound({idx, idx});
            if (cur != seg.begin()) {
                auto left = prev(cur);
                if (s[left->first] == ch && left->second + 1 == idx) {
                    nl = left->first;
                    lens.erase(lens.find(left->second - left->first + 1));
                    seg.erase(left);
                }
            }

            // merge right
            cur = seg.lower_bound({idx + 1, idx + 1});
            if (cur != seg.end()) {
                if (s[cur->first] == ch && cur->first == idx + 1) {
                    nr = cur->second;
                    lens.erase(lens.find(cur->second - cur->first + 1));
                    seg.erase(cur);
                }
            }

            seg.insert({nl, nr});
            lens.insert(nr - nl + 1);

            ans.push_back(*lens.rbegin());
        }

        return ans;
    }
};