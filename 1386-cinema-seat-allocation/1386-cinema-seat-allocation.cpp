class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        unordered_map<int, set<int>> mp;

        // Store reserved seats row-wise
        for (auto &x : reservedSeats) {
            mp[x[0]].insert(x[1]);
        }

        int ans = 2 * (n - mp.size());

        // Check only rows having reserved seats
        for (auto &[row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Check seats 2,3,4,5
            for (int i = 2; i <= 5; i++) {
                if (seats.count(i)) {
                    left = false;
                    break;
                }
            }

            // Check seats 4,5,6,7
            for (int i = 4; i <= 7; i++) {
                if (seats.count(i)) {
                    middle = false;
                    break;
                }
            }

            // Check seats 6,7,8,9
            for (int i = 6; i <= 9; i++) {
                if (seats.count(i)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};