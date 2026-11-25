class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    ll binExp(ll a, ll b) {
        if(b == 0) return 1;

        ll half = binExp(a, b / 2);

        ll result = (half * half) % MOD;

        if(b % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    bool check(vector<int>& nums, int size, int base) {
        int n = nums.size();

        unordered_map<ll, int> mp;

        ll hash = 0;
        ll p = binExp(base, size - 1);

        int i = 0, j = 0;

        while(j < n) {

            hash = (hash * base + nums[j]) % MOD;

            if(j - i + 1 < size) {
                j++;
            }
            else {
                mp[hash]++;

                hash = (hash - (nums[i] * p) % MOD + MOD) % MOD;

                i++;
                j++;
            }
        }

        for(auto &it : mp) {
            if(it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        int base = *max_element(nums.begin(), nums.end()) + 1;

        int l = 1, r = n;
        int result = n;

        while(l <= r) {

            int mid = l + (r - l) / 2;

            if(check(nums, mid, base)) {
                result = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return result;
    }
};