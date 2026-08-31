class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans = {-1, -1};

        if (head == NULL || head->next == NULL || head->next->next == NULL)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int first = -1;
        int last = -1;

        int minDist = INT_MAX;

        while (curr->next != NULL) {

            ListNode* nexti = curr->next;

            // Critical point
            if ((curr->val > prev->val && curr->val > nexti->val) ||
                (curr->val < prev->val && curr->val < nexti->val)) {

                // First critical point
                if (first == -1) {
                    first = index;
                }

                // Distance from previous critical point
                if (last != -1) {
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = nexti;
            index++;
        }

        // Less than 2 critical points
        if (first == last)
            return {-1, -1};

        int maxDist = last - first;

        return {minDist, maxDist};
    }
};