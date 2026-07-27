class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq;
        set<int> s; // which store unique number
        for (int i : nums) {
            if (s.count(i)) continue;
            s.insert(i);
            pq.push(i);
        }
        int n = pq.size();
        if (n < 3) return pq.top();
        pq.pop();
        pq.pop();
        return pq.top();
    }
};