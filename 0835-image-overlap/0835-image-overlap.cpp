class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {

        int n = img1.size();

        vector<pair<int, int>> pos1, pos2;

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) {

                if (img1[i][j] == 1)
                    pos1.push_back({i, j});

                if (img2[i][j] == 1)
                    pos2.push_back({i, j});
            }
        }

        vector<vector<int>> freq(2 * n, vector<int>(2 * n, 0));

        int ans = 0;

        for (auto x : pos1) {
            for (auto y : pos2) {

                int dx = y.first - x.first + n;
                int dy = y.second - x.second + n;

                freq[dx][dy]++;

                ans = max(ans, freq[dx][dy]);
            }
        }

        return ans;
    }
};