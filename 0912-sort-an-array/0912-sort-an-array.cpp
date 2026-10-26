class Solution {
public:
    void mergeSort(int low, int high, vector<int>& nums) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(low, mid, nums);
        mergeSort(mid + 1, high, nums);

        merge(low, mid, high, nums);
    }

    void merge(int low, int mid, int high, vector<int>& nums) {
        vector<int> temp;
        int i = low;      // Starting index of the left half
        int j = mid + 1;  // Starting index of the right half

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        // Copy any remaining elements from the left half
        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        // Copy any remaining elements from the right half
        while (j <= high) {
            temp.push_back(nums[j++]);
        }

        // Copy the sorted elements from temp back into the original nums array
        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return nums;
        
        mergeSort(0, n - 1, nums);
        return nums;
    }
};
