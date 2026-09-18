class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();

        vector<int> start(26, -1);
        vector<int> end(26, 0);
        vector<bool> isValid(26, false);

        vector<string> result;

        // Find first and last occurrence
        for(int i = 0; i < n; i++) {
            int idx = s[i] - 'a';

            if(start[idx] == -1) {
                start[idx] = i;
            }

            end[idx] = i;
        }

        // Find valid intervals
        for(int c = 0; c < 26; c++) {

            if(start[c] == -1)
                continue;

            isValid[c] = true;

            for(int i = start[c]; i <= end[c]; i++) {

                int idx = s[i] - 'a';

                // This character started before our interval
                if(start[idx] < start[c]) {
                    isValid[c] = false;
                    break;
                }

                // Expand interval
                end[c] = max(end[c], end[idx]);
            }
        }

        int lastTakenStart = n;

        // Select non-overlapping intervals
        for(int i = n - 1; i >= 0; i--) {

            int c = s[i] - 'a';

            if(!isValid[c])
                continue;

            if(i == start[c] && end[c] < lastTakenStart) {

                result.push_back(
                    s.substr(i, end[c] - i + 1)
                );

                lastTakenStart = i;
            }
        }

        reverse(result.begin(), result.end());

        return result;
    }
};