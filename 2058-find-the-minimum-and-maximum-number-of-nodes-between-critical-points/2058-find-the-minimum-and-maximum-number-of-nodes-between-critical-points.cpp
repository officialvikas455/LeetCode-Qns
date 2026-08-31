class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> points;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != NULL) {

            ListNode* next = curr->next;

            // local maximum OR local minimum
            if ((curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val)) {
                
                points.push_back(index);
            }

            prev = curr;
            curr = next;
            index++;
        }

        // Less than 2 critical points
        if (points.size() < 2)
            return {-1, -1};

        int mini = INT_MAX;

        // Minimum distance between consecutive critical points
        for (int i = 1; i < points.size(); i++) {
            mini = min(mini, points[i] - points[i - 1]);
        }

        // Maximum distance = first to last
        int maxi = points.back() - points.front();

        return {mini, maxi};
    }
};