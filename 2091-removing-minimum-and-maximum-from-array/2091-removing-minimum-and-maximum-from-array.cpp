class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());

        int minIndex = 0;
        int maxIndex = 0;

        // Find indices of min and max
        for (int i = 0; i < n; i++) {
            if (nums[i] == minElement)
                minIndex = i;

            if (nums[i] == maxElement)
                maxIndex = i;
        }

        // Make minIndex the smaller index
        if (minIndex > maxIndex)
            swap(minIndex, maxIndex);

        // Three possibilities:
        // 1. Remove both from left
        int option1 = maxIndex + 1;

        // 2. Remove both from right
        int option2 = n - minIndex;

        // 3. Remove min from left and max from right
        int option3 = (minIndex + 1) + (n - maxIndex);

        return min({option1, option2, option3});
    }
};