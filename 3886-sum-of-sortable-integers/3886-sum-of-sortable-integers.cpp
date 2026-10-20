class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;

        sort(temp.begin(), temp.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool flag = true;

            for (int i = 0; i < n && flag; i += k) {
                int desc = 0, pos = -1;

                for (int j = 0; j < k; j++) {
                    int a = nums[i + j];
                    int b = nums[i + (j + 1) % k];

                    if (a > b) {
                        desc++;
                        pos = j;
                    }
                }

                if (desc > 1) {
                    flag = false;
                    break;
                }

                int r = (desc == 0) ? 0 : (pos + 1) % k;

                for (int j = 0; j < k; j++) {
                    if (nums[i + (r + j) % k] != temp[i + j]) {
                        flag = false;
                        break;
                    }
                }
            }

            if (flag) ans += k;
        }

        return ans;
    }
};