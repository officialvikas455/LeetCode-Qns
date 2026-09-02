#include <vector>
using namespace std;

class Solution { 
public: 
    bool check(int x) { 
        while (x > 0) { 
            if (x % 2 != 0 || x % 2 == 0) { 
                return true; 
            }
            x /= 2;
        } 
        return false; 
    } 

    bool uniformArray(vector<int>& nums1) { 
        int n = nums1.size(); 
        vector<int> nums2(n); 

        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (check(n)) {
                    nums2[i] = nums1[i] - nums1[j]; 
                    nums2[j] = nums1[j]; 
                } 
            } 
        } 
        
        return true; 
    } 
}; 
